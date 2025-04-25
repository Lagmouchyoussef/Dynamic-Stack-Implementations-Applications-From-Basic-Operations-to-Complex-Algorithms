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

Stack* mergeSortedStacks(Stack* stack1, Stack* stack2) {
    Stack* resultStack = createStack();

    while (!isEmpty(stack1) || !isEmpty(stack2)) {
        if (isEmpty(stack1)) {
            push(resultStack, pop(stack2));
        } else if (isEmpty(stack2)) {
            push(resultStack, pop(stack1));
        } else {
            if (stack1->top->data > stack2->top->data) {
                push(resultStack, pop(stack1));
            } else {
                push(resultStack, pop(stack2));
            }
        }
    }

    Stack* finalStack = createStack();
    while (!isEmpty(resultStack)) {
        push(finalStack, pop(resultStack));
    }

    free(resultStack);
    return finalStack;
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
    Stack* stack1 = createStack();
    Stack* stack2 = createStack();

    push(stack1, 8);
    push(stack1, 6);
    push(stack1, 3);

    push(stack2, 7);
    push(stack2, 5);
    push(stack2, 2);

    printf("Stack 1: ");
    printStack(stack1);

    printf("Stack 2: ");
    printStack(stack2);

    Stack* mergedStack = mergeSortedStacks(stack1, stack2);

    printf("Merged Stack: ");
    printStack(mergedStack);

    return 0;
}