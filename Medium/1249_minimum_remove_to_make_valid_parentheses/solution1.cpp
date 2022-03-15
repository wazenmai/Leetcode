/**
 * Title:  Minimum Remove to Make Valid Parentheses (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, Mar, 2022
 */

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; // left
        stack<int> remove; // right
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push(i);
            else if(s[i] == ')') {
                if (st.empty())
                    remove.push(i);
                else
                    st.pop();
            }
        }
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            if (!st.empty() && st.top() == i) {
                st.pop();
                continue;
            }
            if (!remove.empty() && remove.top() == i) {
                remove.pop();
                continue;
            }
            ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
