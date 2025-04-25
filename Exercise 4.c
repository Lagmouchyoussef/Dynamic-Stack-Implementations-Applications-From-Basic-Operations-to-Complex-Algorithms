#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
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

void push(Stack* stack, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack* stack) {
    if (stack->top == NULL) return '\0';
    Node* temp = stack->top;
    char data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int isPalindrome(const char* str) {
    Stack* stack = createStack();
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        push(stack, str[i]);
    }
    for (int i = 0; i < length; i++) {
        if (str[i] != pop(stack)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char word1[] = "radar";
    char word2[] = "Hello";

    if (isPalindrome(word1)) {
        printf("\"%s\" is a Palindrome\n", word1);
    } else {
        printf("\"%s\" is Not a Palindrome\n", word1);
    }

    if (isPalindrome(word2)) {
        printf("\"%s\" is a Palindrome\n", word2);
    } else {
        printf("\"%s\" is Not a Palindrome\n", word2);
    }

    return 0;
}