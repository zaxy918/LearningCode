#include <iostream>
using namespace std;

int t, n;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 1) {
      cout << "YES\n"
           << 1 << endl;
      continue;
    } else if (n == 3) {
      cout << "YES\n1 2 3" << endl;
      continue;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}