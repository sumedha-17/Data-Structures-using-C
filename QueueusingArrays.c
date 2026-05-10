#include <stdio.h>
#include <stdlib.h> #define MAX_SIZE 100
int queue[MAX_SIZE]; int front = -1, rear = -1;
// Function to check if the queue is empty int isEmpty() {
return front == -1 || front > rear;
}
// Function to check if the queue is full int isFull() {
return rear == MAX_SIZE - 1;
}
// Function to enqueue (insert) an element into the queue void enqueue(int element) {
if (isFull()) { printf("Queue is full, cannot enqueue\n");
return; }
if (front == -1) {
front = 0; }
rear++; queue[rear] = element;
printf("%d enqueued to the queue\n", element);
}
// Function to dequeue (remove) an element from the queue
int dequeue() {
if (isEmpty()) { printf("Queue is empty, cannot dequeue\n");
return -1; }
int dequeued = queue[front];
front++; printf("Dequeued element: %d\n", dequeued); return dequeued;
}
// Function to display the queue elements void displayQueue() {
if (isEmpty()) {
printf("Queue is empty\n");
return; }
printf("Queue elements: "); for (int i = front; i <= rear; i++) {
printf("%d ", queue[i]);
}
printf("\n"); }
int main() {
int choice, element;
do {
printf("\nQueue Operations Menu:\n"); printf("1. Enqueue (Insert) Element\n"); printf("2. Dequeue (Remove) Element\n"); printf("3. Display Queue\n"); printf("4. Exit\n"); printf("Enter your choice: "); scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter element to enqueue: "); scanf("%d", &element); enqueue(element); break;
case 2: dequeue(); break;
case 3: displayQueue(); break;
case 4:
printf("Exiting...\n"); break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 4);
return 0;
}
