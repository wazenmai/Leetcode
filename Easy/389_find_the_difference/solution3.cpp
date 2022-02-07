/**
 * Title:  Find the Difference (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   7, Feb, 2022
 * Method: Use int to calculate the answer
 */

class Solution {
public:
    char findTheDifference(string s, string t) {
        int num = 0;
        for (auto& c : s) {
            num += c - 'a';
        }
        for (auto& c : t) {
            num -= c - 'a';
        }
        return 'a' - num;
    }
};
