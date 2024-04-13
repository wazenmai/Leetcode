/**
 * Title:  Maximum Rectangle (Leetcode Hard 85)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, April, 2024
 * Method: Use stack to calculate the maximum rectangle size.
 * Result: Time complexitty is O(nm), space complexity is O(m). n = matrix.size(), m = matrix[0].size().
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m + 1, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[j] = (matrix[i][j] == '1') ? dp[j] + 1 : 0;
            }

            // Count rectangle size
            stack<pair<int, int>> st;
            for (int j = 0; j < m; j++) {
                int start = j;
                while (!st.empty() && st.top().second >= dp[j]) {
                    ans = max(ans, st.top().second * (j - st.top().first));
                    start = st.top().first;
                    st.pop();
                }
                st.push(make_pair(start, dp[j]));
            }
             while (!st.empty()) {
                ans = max(ans, st.top().second * (m - st.top().first));
                st.pop();
            }
        }
        return ans;
    }
};
