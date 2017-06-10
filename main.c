#include <stdio.h>
#include <stdlib.h>
#include "ring_buffer.h"

int main(int argc, char **argv)
{
    ring_buffer rb;
    init_ring_buffer(&rb, 3, sizeof(int));
    printf("Hello world!\n");
    return 0;
}