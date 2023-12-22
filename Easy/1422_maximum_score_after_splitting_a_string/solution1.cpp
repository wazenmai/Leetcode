/**
 * Title:  Maximum Score After Splitting a String (Leetcode Easy 1422)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, December, 2023
 */

class Solution {
public:
    int maxScore(string s) {
        int zeros = 0;
        int ones = 0;
        for (auto& c: s) {
            if (c == '0') zeros++;
            else ones++;
        }
        int left_zeros = 0;
        int left_ones = 0;
        int score = 0;
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') {
                left_zeros++;
            } else {
                left_ones++;
            }
            score = max(score, left_zeros + ones - left_ones);
        }
        return score;
    }
};
