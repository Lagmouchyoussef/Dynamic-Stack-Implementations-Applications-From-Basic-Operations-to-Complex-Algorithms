#include <stdio.h>
#include <stdlib.h>

typedef struct Animal {
    char name[50];
    int legs;
    struct Animal* next;
} Animal;

typedef struct Stack {
    Animal* top;
} Stack;

Stack* initStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, char* name, int legs) {
    Animal* newAnimal = (Animal*)malloc(sizeof(Animal));
    strcpy(newAnimal->name, name);
    newAnimal->legs = legs;
    newAnimal->next = stack->top;
    stack->top = newAnimal;
}

Animal* pop(Stack* stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    Animal* temp = stack->top;
    stack->top = temp->next;
    return temp;
}

void display(Stack* stack) {
    Animal* current = stack->top;
    while (current != NULL) {
        printf("Animal: %s, Legs: %d\n", current->name, current->legs);
        current = current->next;
    }
}

Animal* peek(Stack* stack) {
    return stack->top;
}

void duplicate(Stack* stack) {
    if (isEmpty(stack)) {
        return;
    }
    Animal* topAnimal = stack->top;
    push(stack, topAnimal->name, topAnimal->legs);
}

void swap(Stack* stack) {
    if (stack->top == NULL || stack->top->next == NULL) {
        return;
    }
    Animal* first = stack->top;
    Animal* second = stack->top->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

void removeBipeds(Stack* stack) {
    Stack* tempStack = initStack();
    while (!isEmpty(stack)) {
        Animal* animal = pop(stack);
        if (animal->legs != 2) {
            push(tempStack, animal->name, animal->legs);
        }
        free(animal);
    }
    while (!isEmpty(tempStack)) {
        Animal* animal = pop(tempStack);
        push(stack, animal->name, animal->legs);
        free(animal);
    }
    free(tempStack);
}

int main() {
    Stack* stack = initStack();
    push(stack, "Dog", 4);
    push(stack, "Chicken", 2);
    push(stack, "Cat", 4);
    push(stack, "Human", 2);
    display(stack);
    printf("Top Animal: %s\n", peek(stack)->name);
    duplicate(stack);
    printf("After Duplicating Top:\n");
    display(stack);
    swap(stack);
    printf("After Swapping Top Two:\n");
    display(stack);
    removeBipeds(stack);
    printf("After Removing Bipeds:\n");
    display(stack);
    return 0;
}