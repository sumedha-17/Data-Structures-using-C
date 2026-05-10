#include <stdio.h>
#include <stdlib.h>
// Define a structure for the queue node struct Node {
int data;
struct Node* next;
};
struct Node* front = NULL; struct Node* rear = NULL;
// Function to check if the queue is empty int isEmpty() {
return front == NULL;
}
// Function to enqueue (insert) an element into the queue void enqueue(int element) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); if (!newNode) {
printf("Memory allocation error\n");
return; } newNode->data = element; newNode->next = NULL;
if (rear == NULL) {
front = rear = newNode;
return; }
rear->next = newNode; rear = newNode; printf("%d enqueued to the queue\n", element);
}
// Function to dequeue (remove) an element from the queue
int dequeue() {
if (isEmpty()) {
printf("Queue is empty, cannot dequeue\n");
return -1; } struct Node* temp = front; int dequeued = temp->data; front = front->next;
if (front == NULL) {
rear = NULL; }
free(temp); return dequeued;
}
// Function to display the queue elements void displayQueue() {
if (isEmpty()) {
printf("Queue is empty\n");
return; }
struct Node* temp = front; printf("Queue elements: "); while (temp != NULL) {
printf("%d ", temp->data); temp = temp->next;
}
printf("\n"); }
int main() {
int choice, element;
do {
printf("\nQueue Operations Menu:\n"); printf("1. Enqueue (Insert) Element\n"); printf("2. Dequeue (Remove) Element\n"); printf("3. Display Queue\n"); printf("4. Exit\n"); printf("Enter your choice: "); scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter element to enqueue: "); scanf("%d", &element); enqueue(element); break; case 2:
printf("Dequeued element: %d\n", dequeue()); break;
case 3: displayQueue(); break;
case 4:
printf("Exiting...\n"); break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 4);
return 0;
}
