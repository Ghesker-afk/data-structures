#include <stdio.h>
#include <stdlib.h>

/* A binary tree in which for each node, value of all
nodes in left subtree is lesser or equal, and value of
all nodes in right subtree is greater. */


// Implementing an binary search tree (BST)

// Node that stores the data, and two references to 
// other nodes (a binary tree can have at most two children)

struct BstNode {
  int data;
  struct BstNode* left;
  struct BstNode* right;
};

// The essential information that we need to keep with us
// during all the process of creating a binary search tree is
// the so-called root node, thus, we should have the its address with a pointer.

struct BstNode* GetNewNode(int data) {
  struct BstNode* newNode = (struct BstNode*) malloc(sizeof(struct BstNode)); 
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

struct BstNode* Insert (struct BstNode* root, int data) {
  if (root == NULL) {
    root = GetNewNode(data);
    return root;
  } else if (data <= root->data) {
    root->left = Insert(root->left, data);
  } else {
    root->right = Insert(root->right, data);
  }
  
  return root;
}

int main(void) {
  struct BstNode* root; // pointer to root node
  root = NULL; // setting tree as empty

  root = Insert(root, 15);
  root = Insert(root, 10);
  root = Insert(root, 20);
}