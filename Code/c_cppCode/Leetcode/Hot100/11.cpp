#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int res = 0, curArea = 0;
    int curHeight;
    while (left < right) {
      curArea = min(height.at(left), height.at(right)) * (right - left);
      res = max(curArea, res);
      if (height.at(left) < height.at(right)) {
        curHeight = height.at(left);
        while (left < height.size() && height.at(left) <= curHeight) left++;
      } else {
        curHeight = height.at(right);
        while (right >= 0 && height.at(right) <= curHeight) right--;
      }
    }
    return res;
  }
};