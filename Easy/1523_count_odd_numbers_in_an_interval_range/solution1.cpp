/**
 * Title:  Count Odd Numbers in an Interval Range (Leetcode Easy 1523)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, Feburary, 2023
 */

class Solution {
public:
    int countOdds(int low, int high) {
        if (low & 1 || high & 1) {
            return (high - low) / 2 + 1;
        }
        return (high - low) / 2;
    }
};
