#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int n = people.size();
    if (n == 1) return 1;
    int l = 0, r = n - 1;
    int ans = 0;
    while (l < r) {
      ans++;
      if (people[l] + people[r] <= limit) {
        l++, r--;
      } else if (people[l] > people[r]) {
        l++;
      } else {
        r--;
      }
    }
    return l == r ? ans + 1 : ans;
  }
};