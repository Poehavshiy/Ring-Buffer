#include <stdio.h>
#include "Ring_Buffer.h"

#define  RING_BUFFER_SIZE 8

void show_ring_buffer(struct Ring_Buffer *buffer) {
    for (int i = 0; i < buffer->size; ++i) {
        printf(" %c", buffer->data[i]);
    }
    printf("%c", '\n');
    printf("write = %d\n", buffer->write);
    printf("read = %d\n\n", buffer->read);
}

int main() {
    char comand = 0;
    char data = 0;
    struct Ring_Buffer *buffer = create_ring_buffer(RING_BUFFER_SIZE);
    show_ring_buffer(buffer);
    int operation_status = 0;
    // w - писать r - читать c -очистить s - размер данных
    while (1) {
        scanf(" %c", &comand);
        scanf(" %c", &data);

        if (comand == EOF) {
            break;
        } else if (comand == 'w') {
            operation_status = write_data(buffer, data);
            if (operation_status <= 0) {
                printf("CANNOT WRITE DATA\n\n");
            }
        } else if (comand == 'r') {
            char for_reading;
            operation_status = read_data(buffer, &for_reading);
            if (operation_status <= 0) {
                printf("CANNOT READ DATA\n\n");
            } else {
                printf("READ DATA = %c\n\n", for_reading);
            }
        } else if (comand == 'c') {
            operation_status = clear_buffer(buffer);
            if (operation_status <= 0) {
                printf("CANNOT CLEAR BUFFER\n\n");
            }
        } else if(comand == 's'){
            int size = 0;
            operation_status = buffer_data_size(buffer, &size);
            if(operation_status <= 0){
                printf("CANNOT CALCULATE SIZE\n\n");
            }else{
                printf("BUFFER SIZE = %d\n\n", size);
            }

        }
        show_ring_buffer(buffer);
    }
    int del_status = delete_buffer(buffer);
    {
        if (del_status == -1) {
            printf("ALREADY DELETED\n\n");
        }
    }
    return 0;
}
