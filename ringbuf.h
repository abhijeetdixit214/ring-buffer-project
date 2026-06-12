#ifndef RINGBUF_H
#define RINGBUF_H

#include <stdint.h>

#define RINGBUF_SIZE 16

typedef struct
{
    uint8_t buffer[RINGBUF_SIZE];
    uint32_t head;
    uint32_t tail;
    uint32_t count;
} RingBuffer;

void ringbuf_init(RingBuffer *rb);

int ringbuf_is_empty(const RingBuffer *rb);
int ringbuf_is_full(const RingBuffer *rb);

uint32_t ringbuf_size(const RingBuffer *rb);
uint32_t ringbuf_capacity(void);

int ringbuf_push(RingBuffer *rb, uint8_t data);
int ringbuf_pop(RingBuffer *rb, uint8_t *data);
int ringbuf_peek(const RingBuffer *rb, uint8_t *data);
void ringbuf_clear(RingBuffer *rb);

#endif