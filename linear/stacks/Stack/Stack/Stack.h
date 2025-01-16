#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void** array; //arr of void pointers to hold generic elements
    size_t size;
    size_t capacity;
} Stack;

Stack* create_stack(size_t capacity);


void resize_stack(Stack* stack);

void push(Stack* stack, void* element, size_t element_size);

void* pop(Stack* stack);

void* peek(Stack* stack);

void free_stack(Stack* stack);