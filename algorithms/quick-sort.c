#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a; // Armazena o valor de 'a' em uma variável temporária.
    *a = *b;      // Atribui o valor de 'b' a 'a'.
    *b = temp;    // Atribui o valor original de 'a' (salvo em temp) a 'b'.
}

int partition(int *A, int start, int end) {
  int pivot = A[end];
  int partitionIndex = start; // set partition index as start initially
  for (int i = start; i < end; i++) {
    if (A[i] <= pivot) {
      swap(&A[i], &A[partitionIndex]); // swap if element is lesser than pivot
      partitionIndex++;
    }
  }

  swap(&A[partitionIndex], &A[end]); // swap pivot with element at partition index
  return partitionIndex;
}

/**
 * @brief sorting the array and parts of partition proccess
 * @param A array to be sorted
 * @param start starting index of array
 * @param end last index of array
 */
void quickSort(int *A, int start, int end) {
  if (start < end) {
    int partitionIndex = partition(A, start, end); // calling partition
    quickSort(A, start, partitionIndex -1);
    quickSort(A, partitionIndex + 1, end);
  }
}

int main(void) {
  int A[] = {7, 6, 5, 4, 3, 2, 1, 0};
  quickSort(A, 0, 7);
  for (int i = 0; i < 8; i++) {
    printf("%d ", A[i]);
  }

  return 0;
}