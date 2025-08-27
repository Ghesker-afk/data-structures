#include <stdio.h>

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

int main(void) {
  int A[] = {2, 4, 5, 7, 13, 14, 15, 23};
  printf("Enter a number: ");
  int x;
  scanf("%d", &x);
  int index = binarySearch(A, 8, x);
  if (index != -1) {
    printf("Number %d is at index %d.\n", x, index);
  } else {
    printf("Number %d not found.\n", x);
  }

  return 0;
}