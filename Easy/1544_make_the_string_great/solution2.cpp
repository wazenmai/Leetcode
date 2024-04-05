/**
 * Title:  Make The String Great (Leetcode Easy 1544)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, April, 2024
 */

class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for (auto& c: s) {
            if (ans.length() > 0 && toupper(c) == toupper(ans.back()) && c != ans.back())
                ans.pop_back();
            else
                ans.push_back(c);
        }
        return ans;
    }
};
