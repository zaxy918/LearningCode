#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int findDuplicate(vector<int> &nums) {
    int slow = 0, fast = 0;
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);
    int ptr = 0;
    while (ptr != slow) {
      slow = nums[slow];
      ptr = nums[ptr];
    }
    return ptr;
  }
};