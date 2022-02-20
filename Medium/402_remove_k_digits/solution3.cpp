/**
 * Title:  Remove K Digits (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, Feb, 2022
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int n = (int)num.length();
        if (n == k)
            return "0";
        ans.push_back(num[0]);
        for (int i = 1; i < n; i++) {
            if (k == 0) {
                // check leading zero
                while (ans[0] == '0')
                    ans.erase(0, 1);

                // check adding zero
                int j = i;
                while (j < n && ans.empty()) {
                    if (num[j] != '0')
                        break;
                    j++;
                }
                while (j < n) {
                    ans.push_back(num[j]);
                    j++;
                }
                break;
            } else if (num[i] < ans.back()) {
                while (num[i] < ans.back() && k > 0) {
                    k--;
                    ans.pop_back();
                }
                ans.push_back(num[i]);
            } else {
                ans.push_back(num[i]);
            }
        }
        while (k > 0 && k--)
            ans.pop_back();
        while (ans[0] == '0')
            ans.erase(0, 1);
        if (ans == "")
            ans = "0";
        return ans;
    }
};
