/**
 * Title:  Reverse Words In A String III (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, October, 2023
 * Method: Make a new string using stack. Time O(N), Space O(N).
 */

class Solution {
public:
    string reverseWords(string s) {
        string news = "";
        stack<char> st;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                st.push(s[i]);
            } else {
                while (!st.empty()) {
                    news += st.top();
                    st.pop();
                }
                news += " ";
            }
        }
        while (!st.empty()) {
            news += st.top();
            st.pop();
        }
        return news;
    }
};
