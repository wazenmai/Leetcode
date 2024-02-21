/**
 * Title:  Bitwise AND of Numbers Range (Leetcode Medium 201)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, February, 2024
 * Method: Brute force leads to TLE. First calculate the power of 2 of left and right, if they are different, return 0. Otherwise, iterate from left to right and do bitwise AND.
 * Result: Time complexity O(n), Space complexity O(1)
 */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if (left == right || left == 0) return left;
        int r = floor(log(right) / log(2));
        int l = floor(log(left) / log(2));
        // cout << l << " " << r << "\n";
        if (l != r) return 0;
        int ans = left;
        for (int i = left; i < right; i++) {
            ans &= i;
        }
        ans &= right;
        return ans;
    }
};
