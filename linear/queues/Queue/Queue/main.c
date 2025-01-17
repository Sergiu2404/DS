#include "Queue.h";

typedef struct {
    int id, age;
    char name[20];
}Person;


int main() {
    Queue* queue = create_queue(4);

    int a = 10, b = 20;
    Person person = { 1, 21, "name" };

    push(queue, &a, sizeof(int));
    push(queue, &b, sizeof(int));
    push(queue, &person, sizeof(Person));

    printf("Front element: %d\n", *(int*)peek(queue));

    int* popped = (int*)pop(queue);
    if (popped) {
        printf("Popped element: %d\n", *popped);
        free(popped);
    }

    int* popped1 = (int*)pop(queue);
    if (popped1) {
        printf("Popped element: %d\n", *popped1);
        free(popped1);
    }

    Person* personPopped = (Person*)pop(queue);
    if (personPopped) {
        printf("Popped element: Person with id %d, name: %s, age %d\n", personPopped->id, personPopped->name, personPopped->age);
        free(personPopped);
    }

    free_queue(queue);

    return 0;
}