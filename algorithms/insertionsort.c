#include <stdio.h>
#include <stdlib.h>

/**
 * @brief function that executes the insertion sort algorithm on an array of integers
 * @param A array of integers
 * @param n number of elements in A
 */
void insertionSort(int *A, int n) {
  for (int i = 1; i < n; i++) {
    int temp = A[i]; // temporary variable to compare against the values in the ordered part

    int position = i; // variable to mark the position of the temp variable

    while (position > 0 && A[position-1] > temp) {
      A[position] = A[position - 1];
      position = position - 1;
    }

    A[position] = temp;  
  }
}

int main(void) {
  int A[] = {6,2,3,1,9,10,15,13,12,17}; // creating an array of integers

  int i, numberOfElements; 

  numberOfElements = sizeof(A) / sizeof(A[0]);

  insertionSort(A, numberOfElements);

  for (i = 0; i < numberOfElements; i++) {
    printf("%d ", A[i]);
  }

  return 0;
}