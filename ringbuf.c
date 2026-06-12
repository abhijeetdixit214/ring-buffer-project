#include "ringbuf.h"

void ringbuf_init(RingBuffer *rb)
{
    rb->head = 0U;
    rb->tail = 0U;
    rb->count = 0U;
}

int ringbuf_is_empty(const RingBuffer *rb)
{
    return (rb->count == 0U);
}

int ringbuf_is_full(const RingBuffer *rb)
{
    return (rb->count == RINGBUF_SIZE);
}

uint32_t ringbuf_size(const RingBuffer *rb)
{
    return rb->count;
}

uint32_t ringbuf_capacity(void)
{
    return RINGBUF_SIZE;
}

int ringbuf_push(RingBuffer *rb, uint8_t data)
{
    if (ringbuf_is_full(rb))
    {
        return -1;
    }

    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1U) % RINGBUF_SIZE;
    rb->count++;

    return 0;
}

int ringbuf_pop(RingBuffer *rb, uint8_t *data)
{
    if ((rb == NULL) || (data == NULL))
    {
        return -1;
    }

    if (ringbuf_is_empty(rb))
    {
        return -1;
    }

    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1U) % RINGBUF_SIZE;
    rb->count--;

    return 0;
}

int ringbuf_peek(const RingBuffer *rb, uint8_t *data)
{
    if ((rb == NULL) || (data == NULL))
    {
        return -1;
    }

    if (ringbuf_is_empty(rb))
    {
        return -1;
    }

    *data = rb->buffer[rb->tail];

    return 0;
}

void ringbuf_clear(RingBuffer *rb)
{
    rb->head = 0U;
    rb->tail = 0U;
    rb->count = 0U;
}