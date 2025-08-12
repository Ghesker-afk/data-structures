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

int main(void) {
  // keep track of the first node in the linked list (essential info)
  struct Node* head = NULL;
  
  head = InsertAtEnd(head, 5);
  head = InsertAtEnd(head, 10);
  head = InsertAtEnd(head, 20);
  PrintNodes(head);
}