/**
 * Title:  Delete Characters to Make Fancy String (Leetcode Easy 1957)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, November, 2024
 */


class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string ans = "";
        char pre = 0;
        int rep = 1;
        for (auto& c: s) {
            if (c == pre) {
                if (rep == 2)
                    continue;
                rep++;
                ans += c;
            } else {
                pre = c;
                rep = 1;
                ans += c;
            }
        }
        return ans;
    }
};
