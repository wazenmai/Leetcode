/**
 * Title:  Summary Ranges (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, Feb, 2022
 * Result: 0ms
 */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string temp = "";
        int n = (int)nums.size();
        if (n == 0)
            return ans;
        temp = to_string(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1)
                continue;
            if (temp == to_string(nums[i-1])) {
                ans.emplace_back(temp);
                temp = to_string(nums[i]);
            } else {
                temp += "->";
                temp += to_string(nums[i-1]);
                ans.emplace_back(temp);
                temp = to_string(nums[i]);
            }
        }
        if (temp == to_string(nums[n-1])) {
            ans.emplace_back(temp);
        } else {
            temp += "->";
            temp += to_string(nums[n-1]);
            ans.emplace_back(temp);
        }
        return ans;
    }
};
