#include <stdio.h>
#include <stdlib.h>

// Creating a struct that represents nodes, which are basically containers with some data and a reference to next node.

typedef struct node {
  int data;
  struct node* next;
} node;

// Adds a new node at the end of the linked list

node* insertAtEnd(node* head, int data) {
  node* newNode = (node*) malloc(sizeof(node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return head;
  }

  node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newNode;

  return head;
}

// Prints all elements in the linked list

void printNodes(node* head) {
  printf("Values:");
  while (head != NULL) {
    printf(" %d", head->data);
    head = head->next;
  }
  printf("\n");
}

node* insertAtBegin(node* head, int data) {
  node* newNode = (node*) malloc(sizeof(node));
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

node* reverse(node* head) {
  node *prev, *current, *next;
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

node* delete(node* head, int n) {
  node* temp1 = head;
  if (n == 1) {
    head = temp1->next;
    free(temp1);
    return head;
  }

  for (int i = 0; i < n - 2; i++) {
    temp1 = temp1->next;
  }

  node* temp2 = temp1->next;
  temp1->next = temp2->next;
  free(temp2);

  return head;
}

int main(void) {
  // keep track of the first node in the linked list (essential info)
  node* head = NULL;

  head = insertAtEnd(head, 5);
  head = insertAtEnd(head, 10);
  head = insertAtEnd(head, 20);
  head = insertAtBegin(head, 30);
  printNodes(head);
  head = reverse(head);
  printNodes(head);
  head = insertAtBegin(head, 10);
  printNodes(head);
  head = delete(head, 1); 
  head = delete(head, 2); 
  printNodes(head);
}