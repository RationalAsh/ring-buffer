#include "ring_buffer.h"

static int is_buffer_empty(ring_buffer *rb)
{
    //Check if the ring buffer is empty
    if(rb->head == rb->tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static int is_buffer_full(ring_buffer *rb)
{
    //Check if ring buffer is full
    //Edge case: If the tail is at the end of the buffer
    if((rb->tail == rb->buffer_end) && (rb->head == rb->buffer))
    {
        return 1;
    }
    else if((char *)(rb->tail) + rb->data_size == rb->head)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int init_ring_buffer(ring_buffer *rb, int max_len, size_t sz)
{
    //Initialize the elements in the buffer.
    rb->buffer = calloc(max_len, sz);
    rb->buffer_end = (char *) rb->buffer + (rb->max_length)*(rb->data_size);
    rb->head = rb->buffer;
    rb->tail = rb->buffer;
    rb->max_length = max_len;
    rb->data_size = sz;
}

int push_data(ring_buffer *rb, void *data)
{
    
}