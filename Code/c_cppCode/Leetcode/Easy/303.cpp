#include <iostream>
#include <vector>
using namespace std;
class NumArray {
private:
  static const int MAX_N = 1e4 + 10;
  int preSum[MAX_N];

public:
  NumArray(vector<int> &nums) {
    for (int i = 1; i <= nums.size(); i++) {
      preSum[i] = preSum[i - 1] + nums.at(i - 1);
    }
  }

  int sumRange(int left, int right) {
    return preSum[right + 1] - preSum[left];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */