/**
 * Title:  Redistribute Characters to Make All Strings Equal (Leetcode Easy 1897)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, December, 2023
 * Method: Count the number of each character, and check if the number of each character is divisible by n
 */

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        int all_len = 0;
        vector<int> alpha(26, 0);
        for (auto& s: words) {
            all_len += s.length();
            for (auto& c: s) {
                alpha[c - 'a']++;
            }
        }
        if (all_len % n != 0)
            return false;
        for (int i = 0; i < 26; i++) {
            if (alpha[i] % n != 0) return false;
        }
        return true;
    }
};
