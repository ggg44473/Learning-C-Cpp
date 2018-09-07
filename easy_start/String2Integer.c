#include <stdio.h>

int atoi(char s[]) {
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
    n = 10 * n + (s[i] - '0');
  }
  return n;
}

// string of HEX
int xtoi(char s[]) {
  int i, n;

  n = 0;
  for (i = 0;; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      n = 16 * n + (s[i] - '0');
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      n = 16 * n + (s[i] - 'A') + 10;
    } else if (s[i] >= 'a' && s[i] <= 'f') {
      n = 16 * n + (s[i] - 'a') + 10;
    } else {
      break;
    }
  }
  return n;
}

// string of binary
int btoi_1(char s[]) {
  int i, n;

  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '1'; i++) {
    n = n + n + (s[i] - '0');  // 2*n == n+n
  }
  return n;
}

int btoi_2(char s[]) {
  int i, n;

  n = 0;
  for (i = 0;; i++) {
    if (s[i] == '0') {
      n = n + n;
    } else if (s[i] == '1') {
      n = n + n + 1;
    } else {
      break;
    }
  }
  return n;
}

int main(int argc, char const *argv[]) {
  int n;

  n = atoi("1234567");
  printf("n = %d\n", n);

  n = xtoi("AA");
  printf("n = %d\n", n);

  n = xtoi("aa");
  printf("n = %d\n", n);

  n = btoi_1("11110");
  printf("n = %d\n", n);

  n = btoi_2("11110");
  printf("n = %d\n", n);

  return 0;
}
