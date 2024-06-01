/**
 * Title:  Score of a String (Leetcode Easy 3110)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, June, 2024
 */

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            score += abs(s[i] - s[i - 1]);
        }
        return score;
    }
};
