Lab 4: Stacks
(Dynamic Implementations & Applications)

Exercise 1: Dynamic Stack Implementation
Task: Implement a dynamic stack using a linked list with:

Init_StackD(): Initialize the stack

StackD_Empty(): Check if empty

PushD(): Push an element

PopD(): Pop the top element

TopD(): Peek the top value

Display_StackD(): Print stack contents
Method:

Use a linked list with a top pointer.

PushD() allocates memory for new nodes.

PopD() frees memory with free().

Exercise 2: Animal Stack Manipulation
Given Functions:

push(): Add an animal to the stack

pop(): Remove the top animal

isEmpty(): Check if stack is empty

Implement:

display(P): Print all animals in stack P.

peek(P): Return the top animal without removal.

duplicate(P): Copy the top animal to the stack’s top.

swap(P): Swap the top two animals.

removeBipeds(P): Delete all animals with exactly 2 legs.

Exercise 3: Remove Duplicates
Task: Eliminate duplicate values in a dynamic stack.
Example:
Input: [5, 10, 15, 10, 20, 5, 25] → Output: [25, 20, 15, 10, 5]
Method:

Use a temporary stack to track unique values.

Before pushing, verify if the value already exists.

Exercise 4: Palindrome Check
Task: Verify if a word is a palindrome using a stack.
Examples:

"radar" → Palindrome

"hello" → Not a palindrome
Method:

Push all characters onto the stack.

Compare with the original string.

Exercise 5: Merge Sorted Stacks
Task: Merge two stacks sorted in descending order into one.
Example:
Stack 1: [8, 6, 3]
Stack 2: [7, 5, 2]
Output: [8, 7, 6, 5, 3, 2]
Method:

Use a temporary stack.

Compare and push larger elements first.

Exercise 6: Stack Operations
Reverse a stack using only standard operations.

Example: 1 → 2 → 3 → 3 → 2 → 1.

Remove consecutive duplicates.

Example: 4 → 4 → 2 → 2 → 3 → 1 → 4 → 2 → 3 → 1.

Exercise 7: City Stack (Linked List)
Task: Manage a stack of cities (Boumerdès region) with:

name (string)

area (km²)

population

Functions:

Add "Corso" to the top.

Delete the third city (from the top).

Remove all cities starting with 'B'.
