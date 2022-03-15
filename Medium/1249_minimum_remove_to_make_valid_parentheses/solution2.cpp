/**
 * Title:  Minimum Remove to Make Valid Parentheses (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, Mar, 2022
 * Method: Use vector instead of stack, so we don't need to reverse string.
 */

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st; // left
        vector<bool> v(n, false); // remove
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push(i);
            else if(s[i] == ')') {
                if (st.empty())
                    v[i] = true;
                else
                    st.pop();
            }
        }
        while (!st.empty()) {
            v[st.top()] = true;
            st.pop();
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (v[i])
                continue;
            ans += s[i];
        }
        return ans;
    }
};
