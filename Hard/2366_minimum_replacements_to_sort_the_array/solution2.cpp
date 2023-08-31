/**
 * Title:  Maximum Ice Cream Bars (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, August, 2023
 * Method: If num is greater than target, we need to seperate them by (nums[i] - 1) / target times. The new target would be nums[i] / (ops + 1).
 */

class Solution {
public:
  long long minimumReplacement(const vector<int>& nums) {
    int target = nums.back();
    long long answer = 0;
    for (int i = nums.size() - 1; i >= 0; --i) {
      int ops = (nums[i] - 1) / target;
      answer += ops;
      target = nums[i] / (ops + 1);
    }
    return answer;
  }
};
