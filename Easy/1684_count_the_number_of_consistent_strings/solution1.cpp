/**
 * Title:  Count the Number of Consistent Strings (Leetcode Easy 1684)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, September, 2024
 */

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> allow(26, 0);
        for (const auto& c: allowed) {
            allow[c - 'a'] = 1;
        }
        int ans = 0;
        for (auto& word: words) {
            bool check = true;
            for (auto& c: word) {
                if (allow[c - 'a'] == 0) {
                    check = false;
                    break;
                }
            }
            if (check) ans++;
        }
        return ans;
    }
};
