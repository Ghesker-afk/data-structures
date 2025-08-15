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

int FibLoop(int n) {
  if (n <= 1) {
    return n;
  }
  int f1, f2, f;
  f1 = 0;
  f2 = 1;
  for (int i = 2; i <= n; i++) {
    f = f1 + f2;
    f1 = f2;
    f2 = f;
  }

  return f;
}

int main(void) {
  int n;
  printf("Type a number: ");
  scanf("%d", &n);

  int result = Factorial(n);
  printf("Result: %d\n", result);

  int x; 
  printf("Type a number: ");
  scanf("%d", &x);
  int fibResult = FibLoop(x);
  printf("Result: %d\n", fibResult);

  return 0;
}