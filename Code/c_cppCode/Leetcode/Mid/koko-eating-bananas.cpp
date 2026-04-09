#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int l = 1, r = 0;
    for (int i = 0; i < piles.size(); i++) {
      r = max(piles[i], r);
    }
    int ans = r, mid;
    while (l <= r) {
      mid = l + (r - l) / 2;
      if (can_eat(piles, mid, h)) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return ans;
  }
  bool can_eat(vector<int> &piles, int mid, int h) {
    long long cost = 0;
    for (int i = 0; i < piles.size(); i++) {
      cost += (long long)(piles[i] + mid - 1) / mid;
    }
    return cost <= h ? true : false;
  }
};