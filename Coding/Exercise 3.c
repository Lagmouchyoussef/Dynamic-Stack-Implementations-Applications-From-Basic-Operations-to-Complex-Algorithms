#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (stack->top == NULL) return -1;
    Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

int contains(Stack* stack, int value) {
    Node* current = stack->top;
    while (current != NULL) {
        if (current->data == value) return 1;
        current = current->next;
    }
    return 0;
}

Stack* removeDuplicates(Stack* inputStack) {
    Stack* tempStack = createStack();
    while (!isEmpty(inputStack)) {
        int current = pop(inputStack);
        if (!contains(tempStack, current)) {
            push(tempStack, current);
        }
    }
    Stack* resultStack = createStack();
    while (!isEmpty(tempStack)) {
        push(resultStack, pop(tempStack));
    }
    free(tempStack);
    return resultStack;
}

void printStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Stack* inputStack = createStack();
    push(inputStack, 5);
    push(inputStack, 10);
    push(inputStack, 15);
    push(inputStack, 10);
    push(inputStack, 20);
    push(inputStack, 5);
    push(inputStack, 25);

    printf("Original Stack: ");
    printStack(inputStack);

    Stack* resultStack = removeDuplicates(inputStack);

    printf("Stack after removing duplicates: ");
    printStack(resultStack);

    return 0;
}