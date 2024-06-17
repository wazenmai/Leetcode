/**
 * Title:  Sum of Square Numbers (Leetcode Medium 633)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, June, 2024
 * Method: Use a hash set to store the square numbers from 0 to sqrt(c), and check if c - i * i is in the set.
 * Result: Time complexity is O(sqrt(c)), space complexity is O(sqrt(c)).
 */

class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> us;
        int i = 0;
        int limit = 46340; // sqrt(INT_MAX)
        while (i < limit && i * i <= c) {
            us.insert(i * i);
            if (us.find(c - i * i) != us.end()) return true;
            i++;
        }
        return false;
    }
};
