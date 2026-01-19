#include <iostream>
#include <unordered_map>
using namespace std;

const int MAX_N = 1e5 + 10;

int N, k, len;
int arr[MAX_N];
// The presum -> earliest index
unordered_map<int, int> earliest;

int main() {
  cin >> N >> k;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  //* The index of sum 0
  earliest[0] = -1;
  for (int i = 0, sum = 0; i < N; i++) {
    sum += arr[i];
    if (earliest.count(sum - k)) len = max(len, i - earliest[sum - k]);
    if (!earliest.count(sum)) earliest[sum] = i;
  }
  cout << len << endl;
  return 0;
}