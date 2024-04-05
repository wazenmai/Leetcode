/**
 * Title:  Maximum Nesting Depth of the Parentheses (Leetcode Easy 1614)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, April, 2024
 */

class Solution {
public:
    int maxDepth(string s) {
        int left = 0;
        int ans = 0;
        for (auto& c: s) {
            if (c == '(') {
                left++;
                ans = max(ans, left);
            } else if (c == ')') {
                left--;
            } else {
                continue;
            }
        }
        return ans;
    }
};
