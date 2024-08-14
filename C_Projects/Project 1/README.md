# Linked List Operations in C

This C program demonstrates basic operations on a singly linked list. It provides a menu-driven interface to perform various linked list operations, including insertion, deletion, searching, and traversal.

## Features

- **Insertion Operations**
  - Insert at the beginning
  - Insert at the end
  - Insert at a specified position

- **Deletion Operations**
  - Delete from the beginning
  - Delete from the end
  - Delete from a specified position

- **Search Operation**
  - Search for a value in the linked list

- **Traversal Operation**
  - Display all elements in the linked list

## Code Structure

- **`struct node`**: Defines a node in the linked list with an integer data field and a pointer to the next node.

- **Functions**
  - `void insertAtBeginning(int n)`: Inserts a new node with the value `n` at the beginning of the list.
  - `void insertAtEnd(int n)`: Inserts a new node with the value `n` at the end of the list.
  - `void insertAtPosition(int n, int pos)`: Inserts a new node with the value `n` at a specified position `pos`.
  - `void deleteAtBeginning()`: Deletes the node at the beginning of the list.
  - `void deleteAtEnd()`: Deletes the node at the end of the list.
  - `void deleteAtPosition(int pos)`: Deletes the node at a specified position `pos`.
  - `void search(int val)`: Searches for a node with the value `val` and prints its position if found.
  - `void display()`: Displays all the elements in the linked list.

## Compilation and Execution

1. Save the code in a file named `linked_list.c`.
2. Open a terminal or command prompt.
3. Navigate to the directory containing `linked_list.c`.
4. Compile the code using `gcc`:
   ```bash
   gcc -o linked_list linked_list.c
