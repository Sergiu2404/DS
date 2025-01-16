#include "Stack.h";


typedef struct {
    int id;
    char name[20];
    int age;
}Person;

int main() {
    Stack* stack = create_stack(5);

    int a = 10;
    push(stack, &a, sizeof(int));

    double b = 24.04;
    push(stack, &b, sizeof(double));

    char str[] = "Test String Element in Stack";
    push(stack, str, sizeof(str));

    Person person = { 1, "Name", 21};
    push(stack, &person, sizeof(Person));

    Person* popped_person = (Person*)pop(stack);
    if (popped_person != NULL) {
        printf("Popped Person: %d, name: %s, age: %d\n", popped_person->id, popped_person->name, popped_person->age);
        free(popped_person);
    }

    char* popped_str = (char*)pop(stack);
    if (popped_str != NULL) {
        printf("Popped string: %s\n", popped_str);
    }

    double* popped_double = (double*)pop(stack);
    if (popped_double != NULL) {
        printf("Popped double: %.2f\n", *popped_double);
        free(popped_double);
    }

    int* popped_int = (int*)pop(stack);
    if (popped_int != NULL) {
        printf("Popped integer: %d\n", *popped_int);
        free(popped_int);
    }

    /*char* popped_str = (char*)pop(stack);
    if (popped_str != NULL) {
        printf("Popped string: %s\n", popped_str);
    }*/


    free_stack(stack);

    return 0;
}