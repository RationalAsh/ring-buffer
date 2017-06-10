#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#define STATUS_FULL 0
#define STATUS_PARTIALLY_FULL 1
#define STATUS_EMPTY 2

#include <stdlib.h>

//Struct for holding ring buffer data.
typedef struct ring_buffer
{
    void *buffer;
    void *head;
    void *tail;
    int max_length;
    size_t data_size;
}ring_buffer;

//Related functions
int init_ring_buffer(ring_buffer *rb, int max_len, size_t sz);
int push_data(ring_buffer *rb, void *data);
void *pop_data(ring_buffer *rb);
void *peek_data(ring_buffer *rb);

#endif