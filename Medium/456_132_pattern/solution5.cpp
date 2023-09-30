/**
 * Title:  132 Pattern (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, September, 2023
 * Method: Min array store i for every j, then find k from the right of nums, use stack to store the possible k.
 * Result: O(N) = O(N) find min array for i + O(N) for maximum n elements would be push and pop from stack.
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return false;

        stack<int> st;
        vector<int> min_array(n);
        min_array[0] = nums[0];
        for (int i = 1; i < n; i++)
            min_array[i] = min(min_array[i - 1], nums[i]);
        for (int j = n - 1; j > 0; j--) {
            if (nums[j] <= min_array[j])
                continue;
            while (!st.empty() && st.top() <= min_array[j]) {
                st.pop();
            }
            if (!st.empty() && st.top() < nums[j])
                return true;
            st.push(nums[j]);
        }
        return false;
    }
};
