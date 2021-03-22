/**
 * Title:  Remove K Digits (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, Mar, 2021
 */

// slower and bigger than solution1
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k == num.length())
            return "0";

        string ans = "";
        stack<char> st;
        char temp;
        int rem = 0;
        int size = num.length();
        int i;

        for (i = 0; i < size; i++) {
            if (st.empty()) {
                st.push(num[i]);
            } else {
                while (!st.empty() && rem < k) {
                    temp = st.top();
                    if (temp > num[i]) {
                        st.pop();
                        rem += 1;
                    } else {
                        break;
                    }
                }
                st.push(num[i]);
            }
            if (rem == k)
                break;
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
        if (i != size) {
            for (int j = i; j < size; j++)
                ans = ans + num[j];
        }
        if (ans == "")
            return "0";
        return ans;
    }
};
