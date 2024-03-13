/**
 * Title:  Find the Pivot Integer (Leetcode Easy 2485)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, March, 2024
 * Method: Use two pointers to accumulate the number from left side and right side. If i == j && left_sum == right_sum, return i or j. Otherwise, return -1.
 * Result: Time complexity O(n), Space complexity O(1). Runtime 0 ms, Memory 7.33 MB.
 */

class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1) return 1;
        int i = 1;
        int j = n;
        int left_sum = 0;
        int right_sum = 0;
        while (i <= j) {
            if (left_sum > right_sum) {
                right_sum += j;
                // cout << "right++ -> " << right_sum << ", " << j << "\n";
                j--;
                if (right_sum == left_sum && i == j) return j;
            } else {
                left_sum += i;
                // cout << "left++ -> " << left_sum << ", " << i << "\n";
                i++;
                if (right_sum == left_sum && i == j) return i;
            }
        }
        return -1;
    }
};
