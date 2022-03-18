/**
 * Title:  Remove Duplicate Letters (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, Mar, 2022
 */

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> v(26, 0);
        vector<bool> check(26, false);
        for (auto& c : s) {
            v[c - 'a']++;
        }
        string ans = "";
        stack<char> st;
        for (auto& c : s) {
            v[c - 'a']--;
            if (st.empty()) {
                st.push(c);
                check[c - 'a'] = true;
            } else if (c > st.top() && !check[c - 'a']) {
                st.push(c);
                check[c - 'a'] = true;
            }
            else if (c < st.top() && !check[c - 'a']) {
                while (!st.empty() && st.top() > c && v[st.top() - 'a']) {
                    check[st.top() - 'a'] = false;
                    st.pop();
                }
                st.push(c);
                check[c - 'a'] = true;
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
