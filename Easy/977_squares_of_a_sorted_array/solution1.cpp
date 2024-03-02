/**
 * Title:  Squares of a Sorted Array (Leetcode Easy 977)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, March, 2024
 * Method: Use stack to store the negative numbers, and pop them out when the positive number is larger than the abs(negative number).
 */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        int n = nums.size();
        if (nums[0] >= 0) {
            ans.resize(n);
            for (int i = 0; i < n; i++)
                ans[i] = nums[i] * nums[i];
            return ans;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                st.push(-nums[i]);
            } else {
                while (!st.empty() && st.top() <= nums[i]) {
                    ans.emplace_back(st.top() * st.top());
                    st.pop();
                }
                ans.emplace_back(nums[i] * nums[i]);
            }
        }
        while (!st.empty()) {
            ans.emplace_back(st.top() * st.top());
            st.pop();
        }
        return ans;
    }
};
