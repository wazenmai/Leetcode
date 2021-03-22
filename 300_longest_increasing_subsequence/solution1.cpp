/**
 * Title:  Longest Increasing Subsequence (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Mar, 2021
 */

// failed when  [0,1,0,3,2,3]

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        stack<int> st;
        int size = nums.size();
        int ans = 0;
        int temp;

        for (int i = 0; i < size; i++) {
            st.push(nums[i]);
            for (int j = i + 1; j < size; j++) {
                temp = st.top();
                if (nums[j] > temp) {
                    st.push(nums[j]);
                }
            }
            ans = max((int)st.size(), ans);
            while (!st.empty()) {
                temp = st.top();
                printf("%d ", temp);
                st.pop();
            }
            printf("\n");
        }
        return ans;
    }
};
