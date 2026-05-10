#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int stack[MAX_SIZE]; int top = -1;
// Function to check if the stack is empty int isEmpty() {
return top == -1;
}
// Function to check if the stack is full int isFull() {
return top == MAX_SIZE - 1;
}
// Function to push (insert) an element onto the stack void push(int element) {
if (isFull()) {
printf("Stack overflow, cannot push\n");
return; }
stack[++top] = element;
printf("%d pushed to the stack\n", element);
}
// Function to pop (remove) an element from the stack int pop() {
if (isEmpty()) {
printf("Stack underflow, cannot pop\n"); return -1; }
int popped = stack[top--]; printf("Popped element: %d\n", popped); return popped;
}
// Function to peek at the top element of the stack without removing it int peek() {
if (isEmpty()) {
printf("Stack is empty, cannot peek\n");
return -1; }
return stack[top];
}
// Function to display the stack elements void displayStack() {
if (isEmpty()) {
printf("Stack is empty\n"); return; }
printf("Stack elements: "); for (int i = 0; i <= top; i++) { printf("%d ", stack[i]);
}
printf("\n"); }
int main() { int choice, element;
do {
printf("\nStack Operations Menu:\n"); printf("1. Push (Insert) Element\n"); printf("2. Pop (Remove) Element\n"); printf("3. Peek (View Top) Element\n"); printf("4. Display Stack\n"); printf("5. Exit\n"); printf("Enter your choice: "); scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter element to push: "); scanf("%d", &element); push(element); break;
case 2: pop(); break;
case 3:
printf("Top element: %d\n", peek());
break;
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
