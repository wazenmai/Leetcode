/**
 * Title:  Score of Parentheses (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, Mar, 2022
 * Method: Only count the score on () and calculate the depth.
 */

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int depth = 0;
        int score = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                depth++;
            else {
                depth--;
                if (s[i - 1] == '(')
                    score += (1 << depth);
            }
        }
        return score;
    }
};
