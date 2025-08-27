#include <stdio.h>

/** @brief function that searchs for an element in a sorted or unsorted array
 * @param A sorted or unsorted array of integers
 * @param n number of elements in array A
 * @param x the element to be found in the array
 * @return index of the element, or -1 if the element doesn't exists in the array
 */
int linearSearch(int *A, int n, int x) {
  for (int i = 0; i <= n - 1; i++) {
    if (A[i] == x) {
      return i;
    }
  }

  return -1;
}

void isElementExists(int x) {
  if (x == -1) {
    printf("The element hasn't been found.\n");
  } else {
    printf("The element has been found.\n");
  }
}

int main(void) {
  int A[] = {1, 4, 7, 9, 21};

  int numberOfElements = sizeof(A) / sizeof(A[0]);
  isElementExists(linearSearch(A, numberOfElements, 7));
  isElementExists(linearSearch(A, numberOfElements, 11));
  isElementExists(linearSearch(A, numberOfElements, 12));

  return 0;
}