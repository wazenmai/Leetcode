/**
 * Title:  Final Prices With a Special Discount in a Shop (Leetcode Easy 1475)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, December, 2024
 * Result: Time complexity O(n), Space complexity O(n).
 */


class Solution {
public:
    vector<int> finalPrices(const vector<int>& prices) {
        int n = prices.size();
        vector<int> ans;
        ans.assign(prices.begin(), prices.end());
        stack<int> st;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                ans[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
