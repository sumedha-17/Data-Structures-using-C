#include <stdio.h> #include <stdlib.h>
struct Node {
int data;
struct Node* next;
};
struct Node* head = NULL;
void displayList() {
if (head == NULL) {
printf("List is empty\n");
return; }
struct Node* temp = head;
printf("Circular Linked List: ");
do {
printf("%d -> ", temp->data); temp = temp->next; } while (temp != head); printf(" (head)\n");
}
void insertAtBeginning(int element) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->data = element;
if (head == NULL) {
head = newNode; newNode->next = head;
} else { struct Node* temp = head; while (temp->next != head) {
temp = temp->next;
} newNode->next = head; head = newNode; temp->next = head;
}
}
void insertAtEnd(int element) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); newNode->data = element;
if (head == NULL) {
head = newNode; newNode->next = head;
} else { struct Node* temp = head; while (temp->next != head) {
temp = temp->next;
} temp->next = newNode; newNode->next = head;
}
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
struct Node* temp = head; int count = 1; while (temp->next != head && count < position - 1) {
temp = temp->next; count++; }
if (count != position - 1) {
printf("Invalid position for insertion\n");
free(newNode);
return; }
newNode->next = temp->next; temp->next = newNode;
}
void deleteAtPosition(int position) { if (head == NULL) {
printf("List is empty. Cannot delete.\n");
return; }
if (position == 1) { if (head->next == head) { free(head);
head = NULL;
} else { struct Node* temp = head; while (temp->next != head) temp = temp->next;
struct Node* del = head; head = head->next; temp->next = head;
free(del);
}
} else { struct Node* temp = head; int count = 1; struct Node* prev = NULL; while (temp->next != head && count < position) {
prev = temp; temp = temp->next; count++; }
if (count != position) {
printf("Invalid position for deletion\n");
return; }
prev->next = temp->next;
free(temp);
}
}
void deleteAtEnd() {
if (head == NULL) {
printf("List is empty. Cannot delete.\n");
return;
}
if (head->next == head) { free(head);
head = NULL;
} else { struct Node* temp = head; struct Node* prev = NULL; while (temp->next != head) {
prev = temp; temp = temp->next;
} prev->next = head;
free(temp);
}
}
void deleteAtBeginning() {
if (head == NULL) {
printf("List is empty. Cannot delete.\n");
return; }
if (head->next == head) { free(head);
head = NULL;
} else { struct Node* temp = head; while (temp->next != head) {
temp = temp->next;
} struct Node* del = head; head = head->next; temp->next = head;
free(del);
}
}
int main() {
int choice, element, position;
do {
printf("\nCircular Linked List Operations Menu:\n");
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
}
} while (choice != 8);
return 0;
}
