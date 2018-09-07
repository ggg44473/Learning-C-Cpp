#include <stdio.h>
#include <stdlib.h>

int F(int n);
int main(int argc, char const *argv[]) {
  int n = 0;
  int y = 0;
  char str[] = "";

  printf("Please enter a number n.\n");
  str[0] = getchar();
  n = atoi(str);
  fflush(stdin);

  y = F(n);
  if (y != -1) {
    printf("y = %d", y);
  }

  return 0;
}

int F(int n) {
  if (n > 2) {
    return F(n - 1) + F(n - 2);
  } else if (n == 1) {
    return 0;
  } else if (n == 2) {
    return 1;
  } else {
    printf("n must be bigger than 0.");
    return -1;
  }
}