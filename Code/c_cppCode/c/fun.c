#include <stdbool.h>
#include <stdio.h>

int min(int a, int b) {
  return (a > b) ? b : a;
}

bool isLeapYear(int year) {
  // return (year % 400 ==0)? true:((year % 100 ==0)? false :((year % 4 == 0)? true:false));
  return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int main() {
  printf("%d", add(1, 2) * 3);
  return 0;
}