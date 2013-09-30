#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int f(int a) {
  if (a < 2) {
    return 1;
  }
  return f(a - 1) + f(a - 2);
}

int main(int argc, char *argv[]) {
  srandom(time(NULL));
  int v = random() % 100 + 30;
  printf("%d\n", f(v));
  return 0;
}
