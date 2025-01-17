#include "Queue.h";

Queue* create_queue(size_t capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        fprintf(stderr, "Memory allocation failed for queue.\n");
        exit(EXIT_FAILURE);
    }

    queue->array = (void**)malloc(capacity * sizeof(void*));
    if (!queue->array) {
        fprintf(stderr, "Memory allocation failed for queue array.\n");
        free(queue);
        exit(EXIT_FAILURE);
    }

    queue->front = 0;
    queue->rear = capacity - 1;
    queue->size = 0;
    queue->capacity = capacity;

    return queue;
}

int is_empty(Queue* queue) {
    return queue->size == 0;
}

int is_full(Queue* queue) {
    return queue->size == queue->capacity;
}

void resize_queue(Queue* queue) {
    size_t new_capacity = queue->capacity * 2;
    void** new_array = (void**)malloc(new_capacity * sizeof(void*));
    if (!new_array) {
        fprintf(stderr, "Memory allocation failed for resized queue array.\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < queue->size; i++) {
        new_array[i] = queue->array[(queue->front + i) % queue->capacity];
    }

    free(queue->array);
    queue->array = new_array;
    queue->front = 0;
    queue->rear = queue->size - 1;
    queue->capacity = new_capacity;
}

void push(Queue* queue, void* element, size_t element_size) {
    if (is_full(queue)) {
        resize_queue(queue);
    }

    queue->rear = (queue->rear + 1) % queue->capacity;

    void* element_copy = malloc(element_size);
    if (!element_copy) {
        fprintf(stderr, "Memory allocation failed for queue element.\n");
        exit(EXIT_FAILURE);
    }
    memcpy(element_copy, element, element_size);

    queue->array[queue->rear] = element_copy;
    queue->size++;
}

void* pop(Queue* queue) {
    if (is_empty(queue)) {
        return NULL;
    }

    void* element = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;

    return element;
}

void* peek(Queue* queue) {
    if (is_empty(queue)) {
        return NULL;
    }

    return queue->array[queue->front];
}

void free_queue(Queue* queue) {
    for (size_t i = 0; i < queue->size; i++) {
        free(queue->array[(queue->front + i) % queue->capacity]);
    }
    free(queue->array);
    free(queue);
}