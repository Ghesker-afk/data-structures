#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Represents the node in a binary search tree data structure, which has there fields: two of them are pointers that references the children node, and one stores data.

struct BstNode {
  double data;
  struct BstNode* left;
  struct BstNode* right;
};

struct BstNode* GetNewNode(double data) {
  struct BstNode* newNode = (struct BstNode*) malloc(sizeof(struct BstNode));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct BstNode* Insert(struct BstNode* root, double data) {
  if (root == NULL) {
    root = GetNewNode(data);
    return root;
  }
  else if (data <= root->data) {
    root->left = Insert(root->left, data);
  }
  else {
    root->right = Insert(root->right, data);
  }

  return root;
}

bool Search(struct BstNode* root, double data) {
  if (root == NULL) {
    return false;
  }
  else if (root->data == data) {
    return true;
  }
  else if (data <= root->data) {
    return Search(root->left, data);
  }
  else {
    return Search(root->right, data);
  }
}

int main(void) {
  struct BstNode* root = NULL; // creating an empty tree
  root = Insert(root, 15.0);
  root = Insert(root, 10.0);
  root = Insert(root, 20.0);
  root = Insert(root, 25.0);
  root = Insert(root, 8.0);
  root = Insert(root, 12.0);
  double number;
  printf("Type a number: ");
  scanf("%lf", &number);
  if (Search(root, number) == true) {
    printf("Found!\n");
  } 
  else {
    printf("Not found\n");
  }
  return 0;
}