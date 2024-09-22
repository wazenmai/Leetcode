/**
 * Title:  K-th Smallest in Lexicographical Order (Leetcode Hard 440)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, September, 2024
 * Method: View lexicographical order as a tree. The root is 1, and each node has at most 10 children, use count_step function to calculate how many steps we need in computing a tree.
 * Result: Time complexity: O(log(n)^2), Space complexity: O(logn).
 */

class Solution {
public:
    int count_step(long long n, long long l, long long r) {
        int steps = 0;
        while (l <= n) {
            steps += min(n + 1, r) - l;
            l *= 10;
            r *= 10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        int cur = 1;
        k -= 1;
        while (k > 0) {
            int subtree = count_step(n, cur, cur + 1);
            if (subtree <= k) {
                cur += 1;
                k -= subtree;
            } else {
                cur *= 10;
                k -= 1;
            }
        }
        return cur;
    }
};

// Time complexity: main while loop run O(logn) times,  `count_step` runs in O(logn) time as it traverses depper level of number by multiplying prefixes by 10 in each iteration.
// Space complexity: the depth of the recursive calculations in countSteps.
