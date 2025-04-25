#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct City {
    char name[50];
    float area;
    int population;
    struct City* next;
} City;

typedef struct Stack {
    City* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, const char* name, float area, int population) {
    City* newCity = (City*)malloc(sizeof(City));
    strcpy(newCity->name, name);
    newCity->area = area;
    newCity->population = population;
    newCity->next = stack->top;
    stack->top = newCity;
}

City* pop(Stack* stack) {
    if (stack->top == NULL) return NULL;
    City* temp = stack->top;
    stack->top = stack->top->next;
    return temp;
}

void removeThirdCity(Stack* stack) {
    if (stack->top == NULL || stack->top->next == NULL || stack->top->next->next == NULL) return;
    City* second = stack->top->next;
    City* third = second->next;
    second->next = third->next;
    free(third);
}

void removeCitiesStartingWithB(Stack* stack) {
    City* current = stack->top;
    City* prev = NULL;

    while (current != NULL) {
        if (current->name[0] == 'B' || current->name[0] == 'b') {
            if (prev == NULL) {
                stack->top = current->next;
            } else {
                prev->next = current->next;
            }
            City* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void printStack(Stack* stack) {
    City* current = stack->top;
    while (current != NULL) {
        printf("City: %s, Area: %.2f km², Population: %d\n", current->name, current->area, current->population);
        current = current->next;
    }
}

int main() {
    Stack* cityStack = createStack();

    push(cityStack, "Boumerdes", 1456.0, 800000);
    push(cityStack, "Boudouaou", 120.5, 50000);
    push(cityStack, "Thenia", 98.3, 40000);
    push(cityStack, "Dellys", 54.2, 30000);

    printf("Original Stack:\n");
    printStack(cityStack);

    push(cityStack, "Corso", 75.0, 20000);
    printf("\nAfter Adding 'Corso':\n");
    printStack(cityStack);

    removeThirdCity(cityStack);
    printf("\nAfter Removing the Third City:\n");
    printStack(cityStack);

    removeCitiesStartingWithB(cityStack);
    printf("\nAfter Removing Cities Starting with 'B':\n");
    printStack(cityStack);

    return 0;
}