/**
 * Title:  Rearrange Array Elements By Sign (Leetcode Medium 2149)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, February, 2024
 * Method: Using two queues to store positive and negative numbers, and then pop them out to form the answer array.
 * Result: Time complexity O(2n) = O(n), Space complexity O(n)
 */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        queue<int> q_negative;
        queue<int> q_positive;
        for (int& num: nums) {
            if (num > 0) q_positive.push(num);
            else q_negative.push(num);
        }
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                ans.emplace_back(q_negative.front());
                q_negative.pop();
            } else {
                ans.emplace_back(q_positive.front());
                q_positive.pop();
            }
        }
        return ans;
    }
};
