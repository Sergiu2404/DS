#include "Stack.h";

Stack* create_stack(size_t capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->array = (void**)malloc(capacity * sizeof(void*));
    stack->size = 0;
    stack->capacity = capacity;
    return stack;
}

void resize_stack(Stack* stack) {
    stack->capacity *= 2;
    stack->array = (void**)realloc(stack->array, stack->capacity * sizeof(void*));
}

void push(Stack* stack, void* element, size_t element_size) {
    if (stack->size == stack->capacity) {
        resize_stack(stack);
    }

    void* element_copy = malloc(element_size);
    memcpy(element_copy, element, element_size);
    stack->array[stack->size++] = element_copy;
}

void* pop(Stack* stack) {
    if (stack->size == 0) {
        return NULL;
    }

    void* element = stack->array[--stack->size];
    return element;
}

// get the top elem without removing
void* peek(Stack* stack) {
    if (stack->size == 0) {
        return NULL;
    }

    return stack->array[stack->size - 1];
}

void free_stack(Stack* stack) {
    for (size_t i = 0; i < stack->size; i++) {
        free(stack->array[i]); // free each elem
    }
    free(stack->array); // free array
    free(stack); //free stack struct
}
