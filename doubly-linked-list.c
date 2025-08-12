#include <stdio.h>
#include <stdlib.h>

// implementing a doubly linked list

// struct that represents the three fields of a node in a doubly linked list: one contains data, and the other two possess references to the next and previous node.

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

// pointer variable that points to the head node, commonly named 'head'

struct Node* head;

struct Node* GetNewNode(int x) {
  struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

  newNode->data = x;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

void InsertAtHead(int x) {
  struct Node* newNode = GetNewNode(x);
  if (head == NULL) {
    head = newNode;
    return;
  }

  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

void PrintNodes() {
  struct Node* temp = head;
  printf("Forward: ");
  while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void ReversePrint() {
  struct Node* temp = head;
  if (temp == NULL) {
    return;
  }

  // We want to go to the last node at the linked list, and thsi is what this loop below actually do
  while (temp->next != NULL) {
    temp = temp->next;
  }

  // traversing backwards using prev pointer
  printf("Reverse: ");
  while(temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->prev;
  }
  printf("\n");
}

int main(void) {
  head = NULL; // empty list
  InsertAtHead(2);
  InsertAtHead(4);
  InsertAtHead(6);
  PrintNodes();
  ReversePrint();
}   