/**
 * Title:  Lexicographical Numbers (Leetcode Medium 386)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, September, 2024
 * Result: Time complexity O(n), Space complexity O(1).
 */

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int cur = 1;
        for (int i = 1; i <= n; i++) {
            ans.emplace_back(cur);
            if (cur * 10 <= n) {
                cur *= 10;
            } else {
                while (cur % 10 == 9 || cur >= n) {
                    cur /= 10;
                } 
                cur += 1;
            }
        }
        return ans;
    }
};

// n = 1000
// 1,10,100,1000,1001,1002,101,102,11,110
