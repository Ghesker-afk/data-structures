#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int A[], int n) {
  for (int i = 0; i < n - 1; i++) { // we need to do n - 2 passes, because the last element (at index n - 1) is correctly placed when the execution ends.

    int indexMin = i; // elements from i till n - 1 are candidates

    for (int j = i + 1; j < n; j++) {
      if (A[j] < A[indexMin]) {
        indexMin = j; // update the index of the minimum element
      } 
    }

    int temp = A[i];
    A[i] = A[indexMin];
    A[indexMin] = temp;
  }
}

int main(void) {
  int A[] = {2, 50, 102, 40, 30};
  SelectionSort(A, 5);
  
  printf("Values:");
  for (int i = 0; i < 5; i++) {
    printf(" %d", A[i]);
  }
  printf("\n");

  return 0;
}