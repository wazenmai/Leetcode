/**
 * Title:  Longest Valid Parenteses (Leetcode Hard 32)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, December, 2024
 * Method: Turn s into 01 array. Ex: "(()" -> [0, 1, 1]" where 1 means match. Then find the longest continuous 1.
 * Result: Time complexity O(n), Space complexity O(n).
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st;
        int n = s.length();
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') {
                if (!st.empty() && st.top().first == '(') {
                    v[i] = 1;
                    v[st.top().second] = 1;
                    st.pop();
                } else {
                    st.push(make_pair(s[i], i));
                }
            } else {
                st.push(make_pair(s[i], i));
            }
        }
        int ans = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0) {
                ans = max(ans, i - start);
                start = i + 1;
            }
        }
        ans = max(ans, n - start);
        return ans;
    }
};
