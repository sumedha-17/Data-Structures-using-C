#include <stdio.h>
#include <stdlib.h>
// Define a structure for the stack node struct Node {
int data;
struct Node* next;
};
struct Node* top = NULL; // Initialize an empty stack
// Function to check if the stack is empty int isEmpty() {
return top == NULL;
}
// Function to push (insert) an element onto the stack void push(int element) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); if (!newNode) {
printf("Memory allocation error\n");
return; } newNode->data = element; newNode->next = top; top = newNode;
printf("%d pushed to the stack\n", element);
}
// Function to pop (remove) an element from the stack int pop() {
if (isEmpty()) {
printf("Stack is empty, cannot pop\n");
return -1; } struct Node* temp = top; int popped = temp->data; top = top->next; free(temp); return popped;
}
// Function to peek at the top element of the stack without removing it int peek() {
if (isEmpty()) { printf("Stack is empty, cannot peek\n"); return -1; } return top->data;
}
// Function to display the stack elements void displayStack() {
if (isEmpty()) {
printf("Stack is empty\n");
return; } struct Node* temp = top; printf("Stack elements: "); while (temp != NULL) {
printf("%d ", temp->data); temp = temp->next;
}
printf("\n"); }
int main() {
int choice, element;
do {
printf("\nStack Operations Menu:\n"); printf("1. Push (Insert) Element\n"); printf("2. Pop (Remove) Element\n"); printf("3. Peek (View Top) Element\n"); printf("4. Display Stack\n"); printf("5. Exit\n"); printf("Enter your choice: "); scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter element to push: "); scanf("%d", &element); push(element); break;
case 2: printf("Popped element: %d\n", pop()); break;
case 3: printf("Top element: %d\n", peek()); break;
case 4:
displayStack(); break;
case 5:
printf("Exiting...\n"); break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 5);
return 0;
}
