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


/** @brief traverses a binary tree in the following order: <root> <left> <right>.
 * @param root pointer to root node of binary tree
 */
void Preorder(node* root) {
  if (root == NULL) {
    return;
  } 
  printf("%d ", root->data);
  Preorder(root->left);
  Preorder(root->right);
}


/** @brief multiplies all the elements in a integer binary tree by a certain integer
 * @param root pointer to root node of binary tree
 * @param value integer to multiply all the node values in a integer binary tree
 */
void Multiply(node* root, int value) {
  if (root == NULL) {
    return;
  } 

  root->data *= value;

  Multiply(root->left, value);
  Multiply(root->right, value);
}

/** @brief traverses a binary tree in the following order: <root> <left> <right>. This traversal type in a binary search tree (BST) will give us the elements in sorted order. Follow this order: <left> <root> <right>.
 * @param root pointer to root node of binary tree
 */
void Inorder(node* root) {
  if (root == NULL) {
    return;
  }
  Inorder(root->left);
  printf("%d ", root->data);
  Inorder(root->right);
}

// Traverse the binary search tree in the order: <left><right><root>.
/** @brief traverses a binary tree in the following order: <left> <right> <root>.
 * @param root pointer to root node of binary tree
 */
void Postorder(node* root) {
  if (root == NULL) {
    return;
  }
  Postorder(root->left);
  Postorder(root->right);
  printf("%d ", root->data);
}


/** @brief function that checks if all the elements in a given tree are lesser than a given value or not
 * @param root pointer to root node of binary tree
 * @param value value to be compared with all the other node values
 * @return returns 1 if all the node values are lesser than value param, 0 otherwise
 */ 
int isSubtreeLesser(node* root, int value) {
  // returns 1 (true) if all elements are lesser or equal to value

  // base case
  if (root == NULL) {
    return 1;
  }

  if (root->data <= value 
  && isSubtreeLesser(root->left, value) == 1
  && isSubtreeLesser(root->right, value) == 1) {
    return 1;
  } else {
    return 0;
  }
}

/** @brief function that checks if all the elements in a given tree are greater than a given value or not
 * @param root pointer to root node of binary tree
 * @param value value to be compared with all the other node values
 * @return returns 1 if all the node values are greater than value param, 0 otherwise
 */ 
int isSubtreeGreater(node* root, int value) {
  // returns 1 (true) of all elements are greater than value

  // base case
  if (root == NULL) {
    return 1;
  }

  if (root->data > value 
  && isSubtreeGreater(root->left, value) == 1
  && isSubtreeGreater(root->right, value) == 1) {
    return 1;
  } else {
    return 0;
  }
}

/** @brief function that verifies if the binary tree is a binary search tree
 * @param root pointer to the root node of binary tree
 * @return return true if binary search tree, false otherwise
 */
int isBinarySearchTree(node* root) {
  if (root == NULL) {
    return 1;
  }

  if (isSubtreeLesser(root->left, root->data) == 1 
  && isSubtreeGreater(root->right, root->data) == 1 
  && isBinarySearchTree(root->left) == 1 
  && isBinarySearchTree(root->right) == 1) {
    return 1;
  } else {
    return 0;
  }
}

/** @brief find the height of a binary tree
 * @param root pointer to the root node of binary tree
 * @return height of the tree
 */
int findHeight(node* root) {
  if (root == NULL) {
    return -1;
  }

  int left = findHeight(root->left);
  int right = findHeight(root->right);
  if (left > right) {
    return left + 1;
  } else {
    return right + 1;
  }
}

int main(void) {
  node* root = NULL; // creating an empty tree
  root = insertNode(root, 15);
  root = insertNode(root, 10);
  root = insertNode(root, 20);
  root = insertNode(root, 25);

  /*
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
*/

Preorder(root);
Multiply(root, 5);
printf("\n");
Preorder(root);
printf("\n");

int isBST = isBinarySearchTree(root);
printf("Value: %d\n", isBST);

int height = findHeight(root);
printf("Height of the tree is: %d\n", height);

return 0;
}