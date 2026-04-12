#include <iostream>
using namespace std;

const int MAXN = 1e3;
int inv[MAXN + 1];
int fac[MAXN + 1];

long long power(int a, int b, int p) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % p;
    }
    a = (a * a) % p;
    b >>= 1;
  }
}

void get_linear_inv(int n, int p) {
  inv[1] = 1;
  for (int i = 2; i <= n; i++) {
    inv[i] = p - (long long)inv[p % i] * (p / i) % p;
  }
}

void get_step_inv(int n, int p) {
  fac[1] = 1;
  for (int i = 2; i <= MAXN; i++) {
    fac[i] = ((long long)i * fac[i - 1]) % p;
  }
  inv[MAXN] = power(fac[MAXN], p - 2, p);
  for (int i = 1; i <= MAXN; i++) {
    inv[i] = ((long long)(i + 1) * inv[i + 1]) % p;
  }
}

int main() {
  int n, p;
  ios::sync_with_stdio(false);
  cin >> n >> p;
  get_linear_inv(n, p);
  for (int i = 1; i <= n; i++) {
    cout << inv[i] << endl;
  }
}