/**
 * Title:  Maximum Width Ramp (Leetcode Medium 962)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, October, 2024
 * Method: Use monotonic dcreasing stack to store number index. Iterate from right to left, if we encountered a number that is greater than stack.top(), we pop the stack until the number is less than stack.top(), and calculate the maximum width. 
 *         This is guaranteed to be correct since the maximum length that st.top() can reach is from the rightest element.
 * Result: Time Complexity: O(n)
 */

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(0);
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[st.top()])
                st.push(i);
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                ans = max(ans, i - st.top());
                st.pop();
            }
        }
        return ans;
    }
};
