#include <stdio.h>
#include <stdlib.h>

/** @brief function to merge arrays L (left) and R (right) into A.
 * @param A general array
 * @param L left array
 * @param R right array 
 * @param leftCount number of elements in L
 * @param rightCount number of elements in R
 */

 void merge(int *A, int *L, int leftCount, int *R, int rightCount) {
  int i, j, k;

  // i - to mark the index of left subarray (L)
  // j - to mark the index of right sub-array (R)
  // k - to mark the index of merged subarray (A)

  i = 0, j = 0, k = 0;

  while(i < leftCount && j < rightCount) {
    if (L[i] < R[j]) 
    {
      A[k++] = L[i++];
    } 
    else 
    {
      A[k++] = R[j++];
    }
  }

  while (i < leftCount) {
      A[k++] = L[i++];
    }

  while (j < rightCount) {
    A[k++] = R[j++];
  }
 }

 /**
  * @brief recursive function to sort an array of integers
  * 
  * @param A array of integers
  * @param n number of elements in A
  */
void mergeSort(int *A, int n) {
  int mid, i, *L, *R;

  // base condition. If the array has less than two element, do nothing.
  if (n < 2) 
  {
    return;
  }

  mid = n / 2; // find the mid index.

  // create left and right subarrays
  // mid elements (from index 0 till mid-1) should be part of left sub-array.
  // and (n-mid) elements (from mid to n-1) will be part of right sub-array.

  L = (int*)malloc(mid * sizeof(int));
  R = (int*)malloc((n - mid) * sizeof(int));

  for (i = 0; i < mid; i++) {
    L[i] = A[i]; // creating left subarray
  }

  for (i = mid; i < n; i++) {
    R[i - mid] = A[i];
  }

  mergeSort(L, mid); // sorting the left subarray
  mergeSort(R, n - mid); // sorting the right subarray
  merge(A, L, mid, R, n - mid); // merging L and R into A as sorted list.

  free(L);
  free(R);
}

int main(void) {

  int A[] = {6,2,3,1,9,10,15,13,12,17}; // creating an array of integers.

  int i, numberOfElements;

  // finding number of elements in array as size of complete array in bytes divided by size of integer in bytes.
  // This won't work if array is passed to the function because array is always passed
  // by reference through a pointer. So sizeof function will give size of pointer and not the array.
  
  numberOfElements = sizeof(A) / sizeof(A[0]);

  // calling merge sort to sort the array.
  mergeSort(A, numberOfElements);

  // printing all elements in the array once its sorted.

  for (i = 0; i < numberOfElements; i++) {
    printf("%d ", A[i]);
  }

  return 0;
}