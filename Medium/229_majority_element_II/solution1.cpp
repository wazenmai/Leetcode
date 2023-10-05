/**
 * Title:  Majority Element II (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, October, 2023
 * Method: Time complexity O(n), space complexity O(n)
 */

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int s = floor(n / 3);
        vector<int> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            if(m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
            } else {
                m[nums[i]]++;
            }
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second > s) {
                ans.emplace_back(it->first);
            }
        }
        return ans;
    }
};
