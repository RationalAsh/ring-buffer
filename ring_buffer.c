#include "ring_buffer.h"

int init_ring_buffer(ring_buffer *rb, int max_len, size_t sz)
{
    rb->buffer = calloc(max_len, sz);
    rb->head = rb->buffer;
    rb->tail = rb->buffer;
    rb->max_length = max_len;
    rb->data_size = sz;
    rb->status = STATUS_EMPTY;
}

int push_data(ring_buffer *rb, void *data)
{
    if((rb->status == STATUS_EMPTY) || (rb->status == STATUS_PARTIALLY_FULL))
    {
        if(rb->tail)
        *(rb->tail) = data;
        rb->tail += rb->data_size;
        rb->status = STATUS_PARTIALLY_FULL;
        (rb->length)++;
    }
}