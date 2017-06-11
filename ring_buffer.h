#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#define STATUS_FULL 0
#define STATUS_PARTIALLY_FULL 1
#define STATUS_EMPTY 2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Struct for holding ring buffer data.
typedef struct ring_buffer
{
    void *buffer;
    void *buffer_end;
    void *head;
    void *tail;
    int length;
    int max_length;
    size_t data_size;
}ring_buffer;

//Related functions
int init_ring_buffer(ring_buffer *rb, int max_len, size_t sz);
int free_ring_buffer(ring_buffer *rb);
int push_data(ring_buffer *rb, void *data);
static int is_buffer_empty(ring_buffer *rb);
static int is_buffer_full(ring_buffer *rb);
int pop_data(ring_buffer *rb, void *data);
void *peek_data(ring_buffer *rb);

#endif