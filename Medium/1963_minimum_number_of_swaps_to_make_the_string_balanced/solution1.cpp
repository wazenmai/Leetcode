/**
 * Title:  Minimum Number of Swaps to Make the String Balanced (Leetcode Medium 1963)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, October, 2024
 */

class Solution {
public:
    int minSwaps(string s) {
        int open = 0;
        int close = 0;
        for (auto& c: s) {
            if (c == '[') {
                open++;
            } else {
                if (open > 0) { // match
                    open--;
                } else { // unbalance
                    close++;
                }
            }
        }
        // now the string like: 11110000, since one swap can fix at most 2 unbalance, we need (close + 1) / 2 swap
        return (close + 1) / 2;
    }
};
