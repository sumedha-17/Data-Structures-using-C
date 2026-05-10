#include <stdio.h> #include <stdlib.h>
struct Node {
int data; struct Node* prev;
struct Node* next;
};
struct Node* head = NULL;
void displayList() {
if (head == NULL) {
printf("List is empty\n");
return; }
struct Node* temp = head; printf("Doubly Linked List: "); while (temp != NULL) { printf("%d <-> ", temp->data); temp = temp->next;
}
printf("NULL\n");
}
void insertAtBeginning(int element) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->data = element; newNode->prev = NULL;
if (head == NULL) {
newNode->next = NULL;
} else { newNode->next = head; head->prev = newNode;
}
head = newNode;
}
void insertAtEnd(int element) { struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->data = element; newNode->next = NULL;
if (head == NULL) { newNode->prev = NULL;
head = newNode;
return; }
struct Node* temp = head; while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newNode; newNode->prev = temp;
}
void insertAtPosition(int element, int position) {
if (position == 1) {
insertAtBeginning(element);
return; }
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->data = element;
if (head == NULL) {
printf("List is empty. Invalid position for insertion\n");
free(newNode);
return; }
struct Node* temp = head; int count = 1; while (temp != NULL && count < position - 1) {
temp = temp->next; count++; }
if (temp == NULL) {
printf("Invalid position for insertion\n");
free(newNode);
return; }
newNode->next = temp->next; newNode->prev = temp;
if (temp->next != NULL) {
temp->next->prev = newNode;
} temp->next = newNode;
}
void deleteAtPosition(int position) { if (head == NULL) {
printf("List is empty. Cannot delete.\n");
return; }
struct Node* temp = head; if (position == 1) { head = head->next; if (head != NULL) {
head->prev = NULL; } free(temp);
return; }
int count = 1; while (temp != NULL && count < position) {
temp = temp->next; count++; }
if (temp == NULL) {
printf("Invalid position for deletion\n");
return; }
if (temp->next != NULL) {
temp->next->prev = temp->prev;
} temp->prev->next = temp->next;
free(temp); }
void deleteAtEnd() {
if (head == NULL) {
printf("List is empty. Cannot delete.\n");
return;
}
struct Node* temp = head; while (temp->next != NULL) {
temp = temp->next;
}
if (temp == head) {
head = NULL;
} else { temp->prev->next = NULL;
} free(temp); }
void deleteAtBeginning() {
if (head == NULL) {
printf("List is empty. Cannot delete.\n");
return; }
struct Node* temp = head; head = head->next; if (head != NULL) {
head->prev = NULL;
} free(temp); }
int main() {
int choice, element, position;
do {
printf("\nDoubly Linked List Operations Menu:\n");
printf("1. Insert at beginning\n"); printf("2. Insert at end\n"); printf("3. Insert at any position\n"); printf("4. Delete at any position\n"); printf("5. Delete at end\n"); printf("6. Delete at beginning\n"); printf("7. Display list\n"); printf("8. Exit\n"); printf("Enter your choice: "); scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter element to insert at the beginning: "); scanf("%d", &element); insertAtBeginning(element); break;
case 2:
printf("Enter element to insert at the end: "); scanf("%d", &element); insertAtEnd(element); break;
case 3:
printf("Enter element to insert: "); scanf("%d", &element); printf("Enter position for insertion: "); scanf("%d", &position); insertAtPosition(element, position); break;
case 4:
printf("Enter position for deletion: "); scanf("%d", &position); deleteAtPosition(position); break;
case 5: deleteAtEnd(); break;
case 6: deleteAtBeginning(); break;
case 7:
displayList(); break;
case 8:
printf("Exiting...\n"); break;
default:
printf("Invalid choice. Please enter a valid option.\n");
} } while (choice != 8); return 0;}
