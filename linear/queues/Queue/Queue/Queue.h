#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void** array;      // arr of void pointers to store elements
    size_t front;      // Index of the front element
    size_t rear;       // Index of the rear element
    size_t size;
    size_t capacity;
} Queue;

Queue* create_queue(size_t capacity);
int is_empty(Queue* queue);

int is_full(Queue* queue);

void resize_queue(Queue* queue);

void push(Queue* queue, void* element, size_t element_size);

void* pop(Queue* queue);

void* peek(Queue* queue);

void free_queue(Queue* queue);