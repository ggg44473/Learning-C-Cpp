#include <stdio.h>

int F(int);
void F_print(int, int *, int *, int *);

int main(int argc, char const *argv[]) {
  int previousTwo = 0;
  int previousOne = 1;
  int y = 0;

  // for loop
  printf("For loop is:\n");
  for (int n = 2; n < 20; n++) {
    y = previousOne + previousTwo;
    printf("%d, ", y);
    previousTwo = previousOne;
    previousOne = y;
  }

  // recursion
  printf("\nRecursion is:\n");
  for (int n = 2; n < 20; n++) {
    printf("%d, ", F(n));
  }

  // recursion including print
  printf("\nRecursion with print is:\n");
  F_print(19, &previousOne, &previousTwo, &y);

  return 0;
}

int F(int n) {
  if (n >= 2) {
    return F(n - 1) + F(n - 2);
  } else if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  }
}

void F_print(int n, int *previousOneP, int *previousTwoP, int *yP) {
  if (n >= 2) {
    F_print((n - 1), previousOneP, previousTwoP, yP);
    *yP = *previousOneP + *previousTwoP;
    printf("%d, ", *yP);
    *previousTwoP = *previousOneP;
    *previousOneP = *yP;
  } else if (n == 1) {
    *previousTwoP = 0;
    *previousOneP = 1;
  }
}