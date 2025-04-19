# Lab 4: Stacks (Implementations and Dynamic Applications)

## Exercise 1: Dynamic Stack Implementation

**Task**: Implement a dynamic stack using a linked list with the following functions:

- `Init_StackD()` : Initialize the stack  
- `StackD_Empty()` : Check if the stack is empty  
- `PushD()` : Push an element  
- `PopD()` : Pop the top element  
- `TopD()` : View the top value  
- `Display_StackD()` : Print the contents of the stack  

**Method**:

- Use a linked list with a top pointer.
- `PushD()` allocates memory for new nodes.
- `PopD()` frees memory using `free()`.

---

## Exercise 2: Animal Stack Manipulation

**Given functions**:

- `push()` : Add an animal to the stack  
- `pop()` : Remove the top animal  
- `isEmpty()` : Check if the stack is empty  

**Implement**:

- `display(P)` : Print all animals in stack `P`.
- `peek(P)` : Return the top animal without removing it.
- `duplicate(P)` : Copy the top animal to the top of the stack.
- `swap(P)` : Swap the top two animals.
- `removeBipeds(P)` : Remove all animals with exactly 2 legs.

---

## Exercise 3: Remove Duplicates

**Task**: Remove duplicates in a dynamic stack.  
**Example**:  
Input: `[5, 10, 15, 10, 20, 5, 25]`  
Output: `[25, 20, 15, 10, 5]`

**Method**:

- Use a temporary stack to track unique values.
- Before pushing, check if the value already exists.

---

## Exercise 4: Palindrome Check

**Task**: Check if a word is a palindrome using a stack.  
**Examples**:  
- "radar" →  Palindrome  
- "Hello" →  Not a palindrome

**Method**:

- Push all characters onto the stack.
- Compare with the original string.

---

## Exercise 5: Merge Sorted Stacks

**Task**: Merge two stacks sorted in descending order into one.  
**Example**:  
Stack 1: `[8, 6, 3]`  
Stack 2: `[7, 5, 2]`  
Result: `[8, 7, 6, 5, 3, 2]`

**Method**:

- Use a temporary stack.
- Compare and push the larger elements first.

---

## Exercise 6: Stack Operations

- Reverse a stack using only standard operations.  
  Example: `1 → 2 → 3 → 3 → 2 → 1`

- Remove consecutive duplicates.  
  Example: `4 → 4 → 2 → 2 → 3 → 1 → 4 → 2 → 3 → 1`

---

## Exercise 7: City Stack (Linked List)

**Task**: Manage a stack of cities (Boumerdès region) with:

- `name` (string)
- `area` (km²)
- `population`

**Functions**:

- Add "Corso" to the top.
- Remove the third city (from the top).
- Remove all cities starting with the letter "B".
