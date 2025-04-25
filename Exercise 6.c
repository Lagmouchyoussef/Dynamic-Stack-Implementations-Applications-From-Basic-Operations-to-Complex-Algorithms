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

void reverseStack(Stack* stack) {
    Stack* tempStack = createStack();
    while (!isEmpty(stack)) {
        push(tempStack, pop(stack));
    }
    while (!isEmpty(tempStack)) {
        push(stack, pop(tempStack));
    }
    free(tempStack);
}

void removeConsecutiveDuplicates(Stack* stack) {
    Stack* tempStack = createStack();
    int prev = -1;
    while (!isEmpty(stack)) {
        int current = pop(stack);
        if (current != prev) {
            push(tempStack, current);
        }
        prev = current;
    }
    while (!isEmpty(tempStack)) {
        push(stack, pop(tempStack));
    }
    free(tempStack);
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
    Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 3);
    push(stack, 2);
    push(stack, 1);

    printf("Original Stack: ");
    printStack(stack);

    reverseStack(stack);
    printf("Reversed Stack: ");
    printStack(stack);

    Stack* stackWithDuplicates = createStack();
    push(stackWithDuplicates, 4);
    push(stackWithDuplicates, 4);
    push(stackWithDuplicates, 2);
    push(stackWithDuplicates, 2);
    push(stackWithDuplicates, 3);
    push(stackWithDuplicates, 1);
    push(stackWithDuplicates, 4);
    push(stackWithDuplicates, 2);
    push(stackWithDuplicates, 3);
    push(stackWithDuplicates, 1);

    printf("Stack with Consecutive Duplicates: ");
    printStack(stackWithDuplicates);

    removeConsecutiveDuplicates(stackWithDuplicates);
    printf("Stack after Removing Consecutive Duplicates: ");
    printStack(stackWithDuplicates);

    return 0;
}