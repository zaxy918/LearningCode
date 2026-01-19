#include <stdio.h>
int b;
void change(int a) {
  a = 0;
}

void change_ptr(int *p) {
  *p = 0;
}
int main() {
  int a = 1;
  char c = 'x';
  long long d;
  char *pc = &c;
  int *p = &a;
  void *q = &b;
  long long *pd = &d;
  printf("a: %p\nb: %p\nc: %p\nd: %p", &a, &b, &c, &d);
  printf("\np: %p\n", p + 1);
  printf("q: %p\n", q + 1);
  printf("pc: %p\n", pc + 1);
  printf("pd: %p\n", pd + 1);

  change(a);
  printf("\na: %d\n", a);
  change_ptr(p);
  printf("a: %d\n", a);
  printf("%d", *p + 1);
  return 0;
}