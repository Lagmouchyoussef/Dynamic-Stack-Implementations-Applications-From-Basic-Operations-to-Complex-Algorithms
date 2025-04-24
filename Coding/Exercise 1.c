#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* Init_StackD() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int StackD_Empty(Stack* stack) {
    return stack->top == NULL;
}

void PushD(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int PopD(Stack* stack) {
    if (StackD_Empty(stack)) {
        return -1;
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedValue;
}

int TopD(Stack* stack) {
    if (StackD_Empty(stack)) {
        return -1;
    }
    return stack->top->data;
}

void Display_StackD(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack* stack = Init_StackD();
    PushD(stack, 10);
    PushD(stack, 20);
    PushD(stack, 30);
    Display_StackD(stack);
    printf("Top: %d\n", TopD(stack));
    printf("Popped: %d\n", PopD(stack));
    Display_StackD(stack);
    return 0;
}