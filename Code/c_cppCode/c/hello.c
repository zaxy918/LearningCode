#include <stdio.h>
int main() {
  printf("Hello world\n");
  long l = 1l;
  long long ln = 1ll;
  unsigned un = 1u;

  float f = 0.1f;
  double d = 0.1 + 0.2;

  int n = 1 << 4;
  short s = 2;
  char c = 'a' + 1;
  // 0001  1
  // 0010  2
  // 1000 -8
  // 1100
  // 1001 -7
  printf("n = %d\n", n);
  printf("f = %f\n", f);
  printf("c = %c\n", c);
  return 0;
}