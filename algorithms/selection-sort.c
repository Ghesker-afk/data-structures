#include <stdio.h>
#include <stdlib.h>

/** @brief function that implements the selection sort algorithm, which sorts an array of integers in increasing order.
 * @param A array of integers
 * @param n length of array A
 */
void selectionSort(int A[], int n) {
  // we need to do n - 2 passes, because the last element 
  // (at index n - 1) is correctly placed when iterations ends.
  for (int i = 0; i <= n - 2; i++) { 

    // elements from i till n - 1 are candidates to be the minimum element in the array
    int indexOfMinimumElement = i; 

    for (int j = i + 1; j <= n - 1; j++) {
      if (A[j] < A[indexOfMinimumElement]) {
        // update the index of the minimum element
        indexOfMinimumElement = j; 
      } 
    }

    int temp = A[i];
    A[i] = A[indexOfMinimumElement];
    A[indexOfMinimumElement] = temp;
  }
}

int main(void) {
  int A[] = {2, 50, 102, 40, 30};

  int sizeOfArray = sizeof(A) / sizeof(A[0]);
  selectionSort(A, sizeOfArray);
  
  printf("Values:");
  for (int i = 0; i < 5; i++) {
    printf(" %d", A[i]);
  }
  printf("\n");

  return 0;
}