#include <stdio.h>
#include <stdlib.h>

// Creating a struct that represents nodes, which are basically containers with some data and a reference to next node

struct Node {
  int data;
  struct Node* next;
};

// Adds a new node at the end of the linked list

struct Node* InsertAtEnd(struct Node* head, int data) {
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return head;
  }

  struct Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;

  return head;
}

// Prints all elements in the linked list

void PrintNodes(struct Node* head) {
  printf("Values:");
  while (head != NULL) {
    printf(" %d", head->data);
    head = head->next;
  }
  printf("\n");
}

struct Node* InsertAtBegin(struct Node* head, int data) {
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return head;
  }

  newNode->next = head;
  head = newNode;

  return head;
}

// Reverse the linked list

struct Node* Reverse(struct Node* head) {
  struct Node *prev, *current, *next;
  current = head;
  prev = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  return prev;
}

// Delete a node from nth position

struct Node* Delete(struct Node* head, int n) {
  struct Node* temp1 = head;
  if (n == 1) {
    head = temp1->next;
    free(temp1);
    return head;
  }

  for (int i = 0; i < n - 2; i++) {
    temp1 = temp1->next;
  }

  struct Node* temp2 = temp1->next;
  temp1->next = temp2->next;
  free(temp2);

  return head;
}

int main(void) {
  // keep track of the first node in the linked list (essential info)
  struct Node* head = NULL;

  head = InsertAtEnd(head, 5);
  head = InsertAtEnd(head, 10);
  head = InsertAtEnd(head, 20);
  head = InsertAtBegin(head, 30);
  PrintNodes(head);
  head = Reverse(head);
  PrintNodes(head);
  head = InsertAtBegin(head, 10);
  PrintNodes(head);
  head = Delete(head, 1); 
  head = Delete(head, 2); 
  PrintNodes(head);
}