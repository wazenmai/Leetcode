/**
 * Title:  Remove K Digits (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Mar, 2021
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.length())
            return "0";

        string ans = "";
        stack<char> st;
        char temp;
        int rem = 0;

        for (auto &c: num) {
            if (st.empty()) {
                st.push(c);
            } else {
                while (!st.empty() && rem < k) {
                    temp = st.top();
                    if (temp > c) {
                        st.pop();
                        rem += 1;
                    } else {
                        break;
                    }
                }
                st.push(c);
            }
        }
        while (rem < k) {
            st.pop();
            rem += 1;
        }
        if (st.empty()) return "0";
        while (!st.empty()) {
            temp = st.top();
            ans = temp + ans;
            st.pop();
        }
        while (ans[0] == '0') {
            ans.erase(ans.begin());
        }
        if (ans == "")
            return "0";
        return ans;
    }
};
