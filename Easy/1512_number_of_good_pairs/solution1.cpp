/**
 * Title:  Number of Good Pairs (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, October, 2023
 */

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j])
                    ans++;
            }
        }
        return ans;
    }
};
