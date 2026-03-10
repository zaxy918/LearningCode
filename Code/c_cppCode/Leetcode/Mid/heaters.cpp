#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int ans = 0;
    int ptrho = 0, ptrhe = 0;
    while (ptrho < houses.size()) {
      int dis = abs(heaters[ptrhe] - houses[ptrho]);
      if (dis <= ans) {
        ptrho++;
      } else if (ptrhe == heaters.size() - 1 || houses[ptrho] < heaters[ptrhe]) {
        ans = dis;
      } else if (houses[ptrho] > heaters[ptrhe]) {
        if (abs(heaters[ptrhe + 1] - houses[ptrho]) > dis) {
          ans = dis;
          ptrho++;
        } else {
          ptrhe++;
        }
      }
    }
    return ans;
  }
  int findRadius2(vector<int> &houses, vector<int> &&heaters) {
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int ans = 0;
    for (int i = 0, j = 0; i < houses.size(); i++) {
      while (!(j == heaters.size() - 1 || abs(heaters[j] - houses[i]) < abs(heaters[j + 1] - houses[i]))) {
        j++;
      }
      ans = max(ans, abs(heaters[j] - houses[i]));
    }
    return ans;
  }
};