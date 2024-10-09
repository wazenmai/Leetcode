/**
 * Title:  Minimum Add to Make Parentheses Valid (Leetcode Medium 921)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, October, 2024
 * Method: Similar to 1963.
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int unbalance = 0;
        for (auto& c: s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    unbalance++;
                }
            }
        }
        return open + unbalance;
    }
};
