#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int len(char s[]) {
  int length = 0;
  int i = 0;
  while (s[i] != '\0') {
    length++;
    i++;
  }
  return length;
}

bool huiword(char s[]) {
  // int l = len(s);
  // for (int i = 0; i < l / 2 + 1; i++) {
  //   if (s[i] == s[l - i - 1]) {
  //     continue;
  //   }
  //   return false;
  // }
  int length = len(s);
  if (length <= 1) return true;
  int l = 0, r = length - 1;
  while (l < r) {
    if (s[l++] != s[r--]) return false;
  }
  return true;
}

int main() {
  // char arr[2];
  // int brr[3];
  // printf("%p\n%p\n", &arr[0], &arr[1]);
  // brr[3] = 1;
  // printf("%d", arr[0]);
  char str[100];
  scanf("%s", &str);
  printf("%d", huiword(str));
  return 0;
}