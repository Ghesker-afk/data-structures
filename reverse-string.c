#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node* top = NULL;

struct Node {
  int data;
  struct Node* next;
};

void Pop();
void Push(int x);
int Top();

void Reverse(char C[], int n) {
  for (int i = 0; i < n; i++) {
    Push(C[i]);
  }

  for (int i = 0; i < n; i++) {
    C[i] = Top();
    Pop();
  }
}

int Top() {
  struct Node* temp = top;
  return temp->data;
}

void Push(int x) {
  struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = top;
  top = temp;
}

void Pop() {
  struct Node* temp;
  if (top == NULL) {
    return;
  }
  temp = top;
  top = top->next;
  free(temp);
}

int main(void) {
  char C[] = "Giovanni";
  Reverse(C, strlen(C));
  printf("Output: %s\n", C);
}