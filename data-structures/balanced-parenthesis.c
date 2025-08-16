#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
  char data;
  struct Node* next;
};

struct Node* top = NULL;

char Top() {
  if (top == NULL) {
    return '\0';
  }
  struct Node* temp = top;
  return temp->data;
}

void Push(char x) {
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

bool arePair(char opening, char closing) {
  if (opening == '(' && closing == ')') {
    return true;
  }
  
  if (opening == '[' && closing == ']') {
    return true;
  }

  if (opening == '{' && closing == '}') {
    return true;
  }
  
  return false;
}

bool CheckBalancedParenthesis(char exp[]) {
  int n = strlen(exp);
  for (int i = 0; i < n; i++) {
    if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
      Push(exp[i]);
    } else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
      if (top == NULL || !arePair(Top(), exp[i])) {
        return false;
      } else {
        Pop();
      }
    }
  }

  if (Top() == '\0') {
    return true;
  } else {
    return false;
  }
}

int main(void) {
  bool result = CheckBalancedParenthesis("{(1 + 2)}");
  if (result) {
    printf("Balanced!\n");
  } else {
    printf("Not balanced.\n");
  }

  bool result2 = CheckBalancedParenthesis("{{(}}");
  if (result2) {
    printf("Balanced!\n");
  } else {
    printf("Not balanced.\n");
  }
  return 0;
}