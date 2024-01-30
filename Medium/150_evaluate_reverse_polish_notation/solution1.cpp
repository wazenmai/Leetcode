/**
 * Title:  Evaluate Reverse Polish Notation (Leetcode Medium 150)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, Janurary, 2024
 * Method: Use my own function is faster than erase s then stoi. Use stack to store the numbers
 */

class Solution {
public:
    int string_to_int(string& s) {
        int i = 1;
        int ans = 0;
        while (i < s.length()) {
            ans = 10 * ans + (s[i] - '0');
            i++;
        }
        return 0 - ans;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& s: tokens) {
            if (s[0] >= '0' && s[0] <= '9') { // number
                st.push(stoi(s));
            } else if (s.length() > 1 && s[0] == '-' && s[1] >= '0' && s[1] <= '9') {
                st.push(string_to_int(s));
            } else {
                int v = st.top();
                st.pop();
                int u = st.top();
                st.pop();
                if (s[0] == '+') {
                    v = u + v;
                } else if (s[0] == '-') {
                    v = u - v;
                } else if (s[0] == '*') {
                    v = u * v;
                } else { // '/'
                    v = u / v;
                }
                st.push(v);
            }
        }
        return st.top();
    }
};
