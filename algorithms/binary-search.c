#include <stdio.h>

/** @brief implementation of binary search algorithm that uses a recursive approach
 * @param A sorted array of integers
 * @param low lowest index of the array
 * @param high highest index of the array
 * @param x the desired element to search in the array
 * @return returns the index of the desired element, or -1 if the element hasn't be found
 */
int recursiveBinarySearch(int *A, int low, int high, int x) {
  // first base condition
  if(low > high) {
    return -1;
  }
  int mid = low + (high - low) / 2;

  // second base condition
  if(x == A[mid]) {
    return mid;
  } else if (x < A[mid]) {
    return recursiveBinarySearch(A, low, mid - 1, x);
  } else {
    return recursiveBinarySearch(A, mid + 1, high, x);
  }
}

 /**
  * @brief: Search for a integer value in a sorted array
  * 
  * @param A sorted array of integers
  * @param n length of array
  * @param x integer to be found
  * @return value that represents the absence or not of the number
  */
int binarySearch(int *A, int n, int x) {
  int low = 0, high = n - 1;

  while(low <= high) {
    // int mid = (low + high) / 2;
    // Avoid overflow by calculating low + high
    int mid = low + (high - low) / 2;
    if (x == A[mid]) {
      return mid;
    } else if (x < A[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return -1;
}

/** @brief function that implements a binary search algorithm which returns the first occurrence of the desired value (x)
 * @param A sorted array of integers
 * @param n number of elements in array A
 * @param x integer to be found in the array
 * @return the index of the element. Returns -1 if the element hasn't be found.
 */
int binarySearchForFirst(int *A, int n, int x) {
  // Use -1 to result because if we doesn't found a occurence of x, then we will return result as -1
  int low = 0, high = n - 1, result = -1;
  while(low <= high) {
    int mid = low + (high - low) / 2;
    if(x == A[mid]) {
      result = mid;
      high = mid - 1;
    } else if (x < A[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return result;
}

/** @brief function that implements a binary search algorithm which returns the last occurrence of the desired value (x)
 * @param A sorted array of integers
 * @param n number of elements in array A
 * @param x integer to be found in the array
 * @return the index of the element. Returns -1 if the element hasn't be found.
 */
int binarySearchForLast(int *A, int n, int x) {
  // Use -1 to result because if we doesn't found a occurence of x, then we will return result as -1
  int low = 0, high = n - 1, result = -1;
  while(low <= high) {
    int mid = low + (high - low) / 2;
    if(x == A[mid]) {
      result = mid;
      low = mid + 1;
    } else if (x < A[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return result;
}

int main(void) {
  int A[] = {2, 4, 5, 7, 13, 13, 14, 15, 23};
  printf("Enter a number: ");
  int x;
  scanf("%d", &x);
  int index = recursiveBinarySearch(A, 0, 8, x);
  if (index != -1) {
    printf("Number %d is at index %d.\n", x, index);
  } else {
    printf("Number %d not found.\n", x);
  }

  return 0;
}