/**
 * Title:  Rearrange Array Elements By Sign (Leetcode Medium 2149)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, February, 2024
 * Method: Since the positions are fixed, we can use two pointers to store positive and negative number idx, and then fill the answer array.
 * Result: Time complexity O(n), Space complexity O(1)
 */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pos = 0, neg = 1;
        for (int num: nums) {
            if (num > 0) {
                ans[pos] = num;
                pos += 2;
            } else {
                ans[neg] = num;
                neg += 2;
            }
        }
        return ans;
    }
};
