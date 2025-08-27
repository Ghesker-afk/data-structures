#include <stdio.h>

void swap(int *x, int *y) { 
   int temp;
   temp = *x;
   *x = *y;
   *y = temp;
}

/** @brief function that sorts an array in increasing order using bubble sort algorithm
 * @param A unsorted (or not) array of integers
 * @param n number of elements in array A
 */ 
void bubbleSort(int *A, int n) {
  int k, i;

  for (k = 1; k <= n - 1; k++) {
    int flag = 0;
    for (i = 0; i <= n - k - 1; i++) {
      if (A[i] > A[i + 1]) {
        swap(&A[i], &A[i + 1]);
      }
    }

    if (flag == 0) {
      break;
    }
  }
}

int main(void) {
  int A[] = {52, 23, 10, 5, 1040, 1004, 432};

  int numberOfElements = sizeof(A) / sizeof(A[0]);
  bubbleSort(A, numberOfElements);

  for (int i = 0; i < numberOfElements; i++) {
    printf("%d ", A[i]);
  }

  return 0;
}