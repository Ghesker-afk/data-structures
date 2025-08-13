#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

// inserts an element at the beginning of the linked list. And why so? It's because the PUSH and POP operations when executed at the beginning of the linked list perform a time complexity of O(1) which is accordingly to the complexity of the stack operations.

void Push(int x) {
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = top;
  top = temp;
}

// Pop up the last element in the stack data structure.

void Pop() {
  struct Node* temp;
  if (top == NULL) {
    return;
  }
  temp = top;
  top = top->next;
  free(temp);
}

struct Node* top = NULL; // stack is empty



