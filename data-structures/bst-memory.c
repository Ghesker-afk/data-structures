#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Represents the node in a binary search tree data structure, which has there fields: two of them are pointers that references the children node, and one stores data.

typedef struct node {
  int data;
  struct node* left;
  struct node* right;
} node;

// Acquires a new node in the heap sectiony of memory, and returns a pointer that stores node's address

struct node* getNewNode(int data) {
  node* newNode = (struct node*) malloc(sizeof(node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}


// Adds a node to the binary search tree, placing nodes with values lesser or equal to the current node on the left subtree, or greater values in the right subtree.

node* insertNode(node* root, int data) {
  if (root == NULL) {
    root = getNewNode(data);
    return root;
  }
  else if (data <= root->data) {
    root->left = insertNode(root->left, data);
  }
  else {
    root->right = insertNode(root->right, data);
  }

  return root;
}

// Verifies if a determined value are in the binary search tree. Returns false if the value is absent.

bool searchValue(node* root, int data) {
  if (root == NULL) {
    return false;
  }
  else if (root->data == data) {
    return true;
  }
  else if (data <= root->data) {
    return searchValue(root->left, data);
  }
  else {
    return searchValue(root->right, data);
  }
}

// Finds the minimum value in the binary search tree.

int findMin(node* root) {
  if (root == NULL) {
    printf("Error: Tree is empty\n");
    return -1;
  }

  while (root->left != NULL) {
    root = root->left;
  }

  return root->data;
}

// Finds the maximum value in the binary search tree.

int findMax(node* root) {
  if (root == NULL) {
    printf("Error: Tree is empty\n");
    return -1;
  }

  while (root->right != NULL) {
    root = root->right;
  }

  return root->data;
}

// Traverse the binary search tree in the order: <root><left><right>.

void Preorder(node* root) {
  if (root == NULL) {
    return;
  } 
  printf("%d ", root->data);
  Preorder(root->left);
  Preorder(root->right);
}

// Inorder traversal in a binary search tree (BST) will give us the elements in sorted order.

void Inorder(node* root) {
  if (root == NULL) {
    return;
  }
  Inorder(root->left);
  printf("%d ", root->data);
  Inorder(root->right);
}

// Traverse the binary search tree in the order: <left><right><root>.

void Postorder(node* root) {
  if (root == NULL) {
    return;
  }
  Postorder(root->left);
  Postorder(root->right);
  printf("%d ", root->data);
}


int main(void) {
  node* root = NULL; // creating an empty tree
  root = insertNode(root, 15);
  root = insertNode(root, 10);
  root = insertNode(root, 20);
  root = insertNode(root, 25);

  int number;
  printf("Type a number: ");
  scanf("%d", &number);
  if (searchValue(root, number) == true) {
    printf("Found!\n");
  } 
  else {
    printf("Not found\n");
  }

  int min = findMin(root);
  int max = findMax(root);
  printf("The min value is %d, and the maximum value is %d.\n", min, max);

  Inorder(root);

  return 0;
}