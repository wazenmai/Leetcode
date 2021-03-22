/**
 * Title:  Valid Parenthesis (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Mar, 2021
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int size = s.length();
        char temp;
        for (int i = 0; i < size; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }
                else {
                   temp =  st.top();
                   if (s[i] == ')' && temp == '(') {
                       st.pop();
                   } else if (s[i] == ']' && temp == '[') {
                       st.pop();
                   } else if (s[i] == '}' && temp == '{') {
                       st.pop();
                   } else {
                       return false;
                   }
                }
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};