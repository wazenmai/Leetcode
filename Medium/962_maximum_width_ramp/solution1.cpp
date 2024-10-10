/**
 * Title:  Maximum Width Ramp (Leetcode Medium 962)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, October, 2024
 * Method: Use a vector to store monotonic decreasing numbers, iterate from left to right, if we encountered a number that is greater than the last element in the vector, we iterate through the vector to find the maximum width.
 * Result: Time Complexity: O(n)
 */

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>> monotonic;
        int n = nums.size();
        int ans = 0;
        monotonic.emplace_back(make_pair(nums[0], 0));
        for (int i = 1; i < n; i++) {
            if (nums[i] < monotonic.back().first) {
                monotonic.emplace_back(make_pair(nums[i], i));
            } else if (nums[i] == monotonic.back().first) {
                ans = max(ans, i - monotonic.back().second);
            } else {
                for (auto& e: monotonic) {
                    if (nums[i] >= e.first) {
                        ans = max(ans, i - e.second);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

// 9810194041
