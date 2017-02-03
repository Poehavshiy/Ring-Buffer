//
// Created by nikita on 02.02.17.
//

#ifndef CYCLE_BUFFER_RING_BUFFER_H
#define CYCLE_BUFFER_RING_BUFFER_H
#include <stddef.h>
#include <stdlib.h>

struct Ring_Buffer{
    int size;//размер буффера
    char* data;// данные
    unsigned read;// указатель чтения
    unsigned write;//указатель записи
};



//создает буффер заданного размера
//вернет NULL в случае передачи значения <= 0 или невозможности выделит память
struct Ring_Buffer* create_ring_buffer(int size);

//Все слудующие функции возвращают -1 если был передан нулевой указатель

// вернет 1 в случае успеха, 0 при неудаче(отсутствии места)
int write_data(struct Ring_Buffer* buffer, char data);

//вернет 1 в случае успеха, 0 при неудаче(отсутствии данных)
int read_data(struct Ring_Buffer *buffer, char *data_output);

//удаления буффера и присвоению указателю NULL
int delete_buffer(struct Ring_Buffer *buffer);

//Очистка буффера read и write устанавливаются в 0
int clear_buffer(struct Ring_Buffer *buffer);

//размер данных
int buffer_data_size(const struct Ring_Buffer *buffer, int* size_output);



#endif //CYCLE_BUFFER_RING_BUFFER_H
