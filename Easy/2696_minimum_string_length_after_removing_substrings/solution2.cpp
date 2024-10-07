/**
 * Title:  Minimum String Length After Removing Substrings (Leetcode Easy 2696)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, October, 2024
 * Method: Stack.
 */

class Solution {
public:
    int minLength(string& s) {
        stack<char> st;
        st.push('Z');
        int n = s.length();
        for (auto c: s) {
            if (st.top() == 'A' && c == 'B') {
                n -= 2;
                st.pop();
            } else if (st.top() == 'C' && c == 'D') {
                n -= 2;
                st.pop();
            } else {
                st.push(c);
            }
        }
        return n;
    }
};
