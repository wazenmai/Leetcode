/**
 * Title:  132 Pattern (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Mar, 2021
 */


class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;

        int size = nums.size();
        int temp;
        bool flag = false;
        
        if (size == 0)
            return false;

        st.push(nums[0]);
        
        for (int i = 1; i < size; i++) {
            flag = false;
            while (!st.empty()) {
                temp = st.top();
                if (temp >= nums[i]) {
                    st.pop();
                    flag = true;
                } else {
                    break;
                }
            }
            if (st.empty()) {
                st.push(nums[i]);
            } else if (temp < nums[i]) {
                if (flag) return true;
                st.push(nums[i]);
            }
        }
        return false;
    }
};