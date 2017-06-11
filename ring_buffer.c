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

void print_ring_buffer(ring_buffer *rb)
{
    int *occupancy = calloc(rb->max_length, sizeof(int));
    //Prints out the entire ring buffer for debugging
    printf("Printing ring buffer...\n");
    printf("-----------------------------");
    printf("");
    
    free(occupancy);
}

int init_ring_buffer(ring_buffer *rb, int max_len, size_t sz)
{
    //Initialize the elements in the buffer.
    rb->buffer = calloc(max_len, sz);
    rb->buffer_end = (char *) rb->buffer + (rb->max_length)*(rb->data_size);
    rb->head = rb->buffer;
    rb->tail = rb->buffer;
    rb->length = 0;
    rb->max_length = max_len;
    rb->data_size = sz;

    if(rb->buffer == NULL)
    {
        printf("Failed to allocate memory for ring buffer!\n");
        return -1;
    }
    else
    {
        return 0;
    }
           
}

int push_data(ring_buffer *rb, void *data)
{
    //Push data into the ring buffer.
    //If the buffer is empty
    if(is_buffer_empty(rb))
    {
        if(rb->tail == rb->buffer_end)
        {
            rb->tail = rb->buffer;
            memcpy(rb->tail, data, rb->data_size);
            rb->length++;
        }
        else
        {
            rb->tail = (char *)rb->tail + rb->data_size;
            memcpy(rb->tail, data, rb->data_size);
            rb->length++;
        }
    }
    else if(is_buffer_full(rb))
    {
        if(rb->tail == rb->buffer_end)
        {
            rb->tail = rb->buffer;
            rb->head = (char *) rb->head + rb->data_size;
            memcpy(rb->tail, data, rb->data_size);
        }
        else if(rb->head == rb->buffer_end)
        {
            rb->tail = (char *)rb->tail + rb->data_size;
            rb->head = rb->buffer;
            memcpy(rb->tail, data, rb->data_size);
        }
        else
        {
            rb->tail = (char *) rb->tail + rb->data_size;
            rb->head = (char *) rb->head + rb->data_size;
            memcpy(rb->tail, data, rb->data_size);
        }
    }
    else
    {
        if(rb->tail == rb->buffer_end)
        {
            rb->tail = rb->buffer;
            memcpy(rb->tail, data, rb->data_size);
        }
        else
        {
            rb->tail = (char *) rb->tail + rb->data_size;
            memcpy(rb->tail, data, rb->data_size);
        }
    }

    return 0;   
}

int pop_data(ring_buffer *rb, void *data)
{
    //Pop data and return a pointer to the data
    if(is_buffer_empty(rb))
    {
        return -1;
    }
    else
    {
        if()
    }
}