/**
 * Title:  Largest Combination With Bitwise AND Greater Than Zero (Leetcode Medium 2275)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, November, 2024
 * Method: If a sequence of numbers has a bitwise AND greater than zero, then there must be at least one bit that is 1 in all numbers. So we can count the number of 1s in each bit of all numbers, and the maximum number of 1s in each bit is the answer.
 * Result: Time complexity is O(n). Space complexity is O(1).
 */

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> setbit(25, 0); // pos 0 - 24
        for (int cand: candidates) {
            int i = 0;
            while (cand > 0) {
                setbit[i++] += (cand & 1);
                cand >>= 1;
            }
        }
        int ans = 1;
        for (int i = 0; i < 25; i++) {
            ans = max(ans, setbit[i]);
        }
        return ans;
    }
};
