#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  static const int MAX_N = 1e6;
  int high = 31;
  int trie[MAX_N][2];
  int cnt = 1;
  int findMaximumXOR(vector<int> &nums) {
    int res = INT_MIN;
    // Build the trie
    build(nums);
    // Find the maxXOR
    for (auto n : nums) {
      res = max(res, maxXOR(n));
    }
    return res;
  }

  int findMaximumXOR2(vector<int> &nums) {
    int res = 0;
    // Find the highst 1;
    highest1(nums);
    // Traversal all bits
    for (int i = high - 1; i >= 0; i++) {
      // Assume we can reach 1 in this bit
      int better = res | (1 << i);
      unordered_set<int> hashset;
      for (auto num : nums) {
        // Keep bits from high to i
        num = (num >> i) << i;
        hashset.insert(num);
        if (hashset.count(num ^ better)) {
          res = better;
          break;
        }
      }
    }
    return res;
  }

  int highest1(vector<int> &nums) {
    int maxn = INT_MIN;
    for (auto n : nums) {
      maxn = max(n, maxn);
    }
    int maxbit = 1 << 30;
    while ((maxbit & maxn) == 0 && high > 0) {
      maxbit >>= 1;
      high--;
    }
  }

  void build(vector<int> &nums) {
    // Find the highest 1
    highest1(nums);
    // Build from the highest 1
    for (auto n : nums) {
      insert(n);
    }
  }

  void insert(int n) {
    int cur = 1;
    for (int i = high - 1, path; i >= 0; i--) {
      path = (n >> i) & 1;
      if (trie[cur][path] == 0) trie[cur][path] = ++cnt;
      cur = trie[cur][path];
    }
  }

  int maxXOR(int n) {
    int cur = 1;
    int res = 0;
    for (int i = high - 1, expect; i >= 0; i--) {
      expect = !((n >> i) & 1);
      if (trie[cur][expect]) {
        res |= 1 << i;
        cur = trie[cur][expect];
      } else {
        cur = trie[cur][!expect];
      }
    }
    return res;
  }
};

int main() {
  vector<int> nums({3, 10, 5, 25, 2, 8});
  Solution *s = new Solution;
  s->findMaximumXOR(nums);
}