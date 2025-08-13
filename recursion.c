#include <stdio.h>
#include <stdlib.h>

int Factorial(int n) {
  if (n == 0) {
    return 1;
  }
  else
  {
    return n*Factorial(n - 1);
  }
}

int main(void) {
  int n;
  printf("Type a number: ");
  scanf("%d", &n);

  int result = Factorial(n);
  printf("Result: %d\n", result);

  return 0;
}