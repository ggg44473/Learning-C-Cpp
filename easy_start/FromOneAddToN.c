#include <stdio.h>

int F(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n + F(n - 1);
  }
}

int main(int argc, char const *argv[]) {
  int n;
  printf("N = ? ");
  scanf("%d", &n);
  fflush(stdin);
  printf("1+2+...+%d = %d", n, F(n));
  return 0;
}
