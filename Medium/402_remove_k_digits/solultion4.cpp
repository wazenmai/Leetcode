/**
 * Title:  Remove K Digits (Leetcode Medium 402)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, April, 2024
 * Method: use i to record # of leading zero and only cal `erase` once to accelerate.
 * Result: Time complexity is O(n), space complexity is O(1). n = num.size().
 */

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int n = num.length();
        ans = num[0];
        for (int i = 1; i < n; i++) {
            if (num[i] < ans.back()) {
                while (k > 0 && !ans.empty() && num[i] < ans.back()) {
                    ans.pop_back();
                    k--;
                }
            }
            ans.push_back(num[i]);
        }
        while (k--) ans.pop_back();
        int i = 0;
        while (ans[i] == '0') i++;
        ans.erase(0, i);
        if (ans == "") return "0";
        return ans;
    }
};
