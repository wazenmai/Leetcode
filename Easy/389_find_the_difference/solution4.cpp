/**
 * Title:  Find the Difference (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   7, Feb, 2022
 * Method: Use bit operation to check - 0 ^ X = X, X ^ X = 0
 */

class Solution {
public:
    char findTheDifference(string s, string t) {
        char check = 0;
        for (auto& c : s) {
            check ^= c;
        }
        for (auto& c : t) {
            check ^= c;
        }
        return check;
    }
};
