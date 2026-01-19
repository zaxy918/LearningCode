#include <stdbool.h>
#include <stdio.h>

long long abs2(void *p, char type) {
  int val;
  if (type == 'i') {
    val = *(int *)p;
  } else if (type == 'l') {
    val = *(long long *)p;
  }
  return val > 0 ? val : -val;
}

int abs(int val) {
  return val < 0 ? -val : val;
}

int main() {
  long long val = -19929367890LL;
  int val2 = -111;
  printf("%d %lld", abs2(&val2, 'i'), abs2(&val, 'l'));
  // if (a == true && !false)
  //   printf("a is true\n");
  // else
  //   printf("a is false\n");

  // do {
  //   printf("in do while\n");
  // } while (false);

  // for (int i = 0; i < 3; i++) {
  //   for (int j = 0; j < 2; j++) {
  //     printf("i = %d, j = %d\n", i, j);
  //   }
  // }

  // int b = a++;
  // // b = a;
  // // a += 1;
  // int c = ++a;
  // // a += 1;
  // // c = a;
  // printf("a = %d, b = %d, c = %d\n", a++, b, c);
  // if (!a == 0 || a++) {
  //   printf("a = %d\n", a);
  // }
  // printf("a = %d\n", a);
  return 0;
}