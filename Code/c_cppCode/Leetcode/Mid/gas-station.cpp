#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int size = gas.size();
    vector<int> rest(size);
    for (int i = 0; i < size; i++) {
      rest[i] = gas[i] - cost[i];
    }
    for (int l = 0, r = 0, remain = 0; l < size; l++, r++) {
      if (rest[l] >= 0) {
        remain = rest[l];
        r++;
        while (remain >= 0) {
          if (l == r % size) return l;
          remain += rest[r++ % size];
        }
        if (r % size > l)
          l = r-- % size - 1;
        else
          return -1;
      }
    }
    return -1;
  }
  int canCompleteCircuit2(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    for (int l = 0, r = 0, sum; l < n; l = r + 1, r = l) {
      sum = 0;
      while (sum + gas[r % n] - cost[r % n] >= 0) {
        if (r - l + 1 == n) return l;
        sum += gas[r % n] - cost[r % n];
        r++;
      }
    }
    return -1;
  }
};
