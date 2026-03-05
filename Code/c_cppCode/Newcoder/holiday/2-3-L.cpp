#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  n %= 10;
  if (n == 0)
    cout << 1 << endl;
  else if (n == 1 || n == 3 || n == 7 || n == 9)
    cout << 10 << endl;
  else if (n == 2 || n == 4 || n == 6 || n == 8)
    cout << 5 << endl;
  else if (n == 5)
    cout << 2 << endl;
  return 0;
}