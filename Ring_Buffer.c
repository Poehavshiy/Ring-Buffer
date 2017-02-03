//
// Created by nikita on 02.02.17.
//
#include "Ring_Buffer.h"


struct Ring_Buffer *create_ring_buffer(int size) {
    if (size <= 0) {
        return NULL;
    }
    struct Ring_Buffer *buffer_ptr = (struct Ring_Buffer *) malloc(sizeof(struct Ring_Buffer));
    if (buffer_ptr == NULL) {
        return NULL;
    }
    buffer_ptr->data = (char *) malloc(sizeof(char) * size);
    if (buffer_ptr->data == NULL) {
        free(buffer_ptr);
        return NULL;
    }
    buffer_ptr->size = size;
    buffer_ptr->read = 0;
    buffer_ptr->write = 0;
    return buffer_ptr;
}

int write_data(struct Ring_Buffer *buffer, char data) {
    if (buffer == NULL) {
        return -1;
    }
    unsigned next = buffer->write + 1;
    if (next == buffer->size) {
        next = 0;
    }
    if (next == buffer->read) {
        return 0;
    }
    buffer->data[buffer->write] = data;
    buffer->write = next;
    return 1;
}

//
int read_data(struct Ring_Buffer *buffer, char *data_output) {
    if (buffer == NULL) {
        return -1;
    }
    if (buffer->write == buffer->read) {
        return 0;
    }
    *data_output = buffer->data[buffer->read];

    unsigned next = buffer->read + 1;
    if (next == buffer->size) {
        next = 0;
    }
    buffer->read = next;
    return 1;
}

//
int delete_buffer(struct Ring_Buffer *buffer) {
    if (buffer == NULL) {
        return -1;
    }
    free(buffer->data);
    free(buffer);
    buffer = NULL;
    return 1;
}

//
int clear_buffer(struct Ring_Buffer *buffer) {
    if (buffer == NULL) {
        return -1;
    }
    buffer->read = 0;
    buffer->write = 0;
    return 1;
}

//
int buffer_data_size(const struct Ring_Buffer *buffer, int *size_output) {
    if (buffer == NULL) {
        return -1;
    }
    if (buffer->read <= buffer->write) {
        *size_output = buffer->write - buffer->read;
        return 1;
    }
    *size_output = (buffer->size - buffer->read) + buffer->write;
    return 1;
}


