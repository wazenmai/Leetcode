/**
 * Title:  Count Number of Maximum Bitwise-OR Subsets (Leetcode Medium 2044)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, October, 2024
 * Result: Time complexity O(2 ** n).
 */

class Solution {
private:
    int ans;
public:
    void check(vector<int>& nums, int i, int cur, int maximum) {
        if (i == nums.size()) {
            if (cur == maximum) ans++;
            return;
        }
        // choose i
        check(nums, i + 1, (cur | nums[i]), maximum);
        // not choose i
        check(nums, i + 1, cur, maximum);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maximum = 0;
        for (auto& num: nums) {
            maximum |= num;
        }
        ans = 0;
        check(nums, 0, 0, maximum);
        return ans;
    }
};
