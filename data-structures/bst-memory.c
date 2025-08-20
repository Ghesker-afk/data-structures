#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct BstNode* GetNewNode(double data);

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

double FindMin(struct BstNode* root) {
  if (root == NULL) {
    printf("Error: Tree is empty\n");
    return -1.0;
  }

  while (root->left != NULL) {
    root = root->left;
  }

  return root->data;
}

double FindMax(struct BstNode* root) {
  if (root == NULL) {
    printf("Error: Tree is empty\n");
    return -1.0;
  }

  while (root->right != NULL) {
    root = root->right;
  }

  return root->data;
}

void Preorder(struct BstNode* root) {
  if (root == NULL) {
    return;
  } 
  printf("%.2lf ", root->data);
  Preorder(root->left);
  Preorder(root->right);
}

// Inorder traversal in a binary search tree (BST) will give us the elements in sorted order.

void Inorder(struct BstNode* root) {
  if (root == NULL) {
    return;
  }
  Inorder(root->left);
  printf("%lf ", root->data);
  Inorder(root->right);
}


void Postorder(struct BstNode* root) {
  if (root == NULL) {
    return;
  }
  Postorder(root->left);
  Postorder(root->right);
  printf("%c ", root->data);
}


int main(void) {
  struct BstNode* root = NULL; // creating an empty tree
  root = Insert(root, 15.0);
  root = Insert(root, 10.0);
  root = Insert(root, 20.0);
  root = Insert(root, 25.0);
  root = Insert(root, 8.0);
  root = Insert(root, 12.0);
  root = Insert(root, 35.0);
  double number;
  printf("Type a number: ");
  scanf("%lf", &number);
  if (Search(root, number) == true) {
    printf("Found!\n");
  } 
  else {
    printf("Not found\n");
  }

  int min = FindMin(root);
  int max = FindMax(root);
  printf("The min value is %d, and the maximum value is %d.\n", min, max);

  Preorder(root);
  Postorder(root);
  Inorder(root);


  return 0;
}