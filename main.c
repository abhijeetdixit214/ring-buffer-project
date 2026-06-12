#include <stdio.h>
#include <stdint.h>

#include "ringbuf.h"

int main(void)
{
    RingBuffer rb;
    uint8_t value;

    ringbuf_init(&rb);

    printf("Capacity = %u\n", ringbuf_capacity());

    printf("\nWriting data:\n");

    for (uint8_t i = 1; i <= 10; i++)
    {
        if (ringbuf_push(&rb, i) == 0)
        {
            printf("Pushed %u\n", i);
        }
        else
        {
            printf("Buffer Full\n");
        }
    }

    printf("\nCurrent Size = %u\n", ringbuf_size(&rb));

    if (ringbuf_peek(&rb, &value) == 0)
    {
        printf("Peek = %u\n", value);
    }

    printf("\nReading data:\n");

    while (!ringbuf_is_empty(&rb))
    {
        if (ringbuf_pop(&rb, &value) == 0)
        {
            printf("Popped %u\n", value);
        }
    }

    printf("\nBuffer Empty = %d\n", ringbuf_is_empty(&rb));

    return 0;
}