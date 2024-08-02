/**
 * Title:  Number of Senior Citizens (Leetcode Easy 2678)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, August, 2024
 */

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int senior = 0;
        for (auto& s: details) {
            if ((s[11] - '0') * 10 + (s[12] - '0') > 60)
                senior++;
        }
        return senior;
    }
};
