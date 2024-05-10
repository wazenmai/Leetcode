/**
 * Title:  K-th Smallest Prime Fraction (Leetcode Medium 786)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, May, 2024
 * Method: Use binary search to find the kth smallest fraction. Every time we get a mid from 0 ~ 1, we calculate # of fractions < mid, if it equals k, return the fraction with maximum value.
 * Result: Time complexity O(nlog(m^2)), space complexity O(1), m = maximum value in array
 */

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0.0;
        double r = 1.0;
        while (l < r) {
            double mid = (l + r) / 2;
            double maxf = 0.0; // store the maximum fraction encountered
            int small = 0; // # of fractions smaller than mid
            int up = 0, down = 0; // index of maxf
            int j = 1; // denominator index
            for (int i = 0; i < n - 1; i++) {
                while (j < n && arr[i] >= mid * arr[j]) {
                    j++;
                }
                small += (n - j);
                if (j == n) break;

                double f = (double)arr[i] / arr[j];
                if (f > maxf) {
                    up = i;
                    down = j;
                    maxf = f;
                }
            }
            if (small == k) {
                return vector<int>{arr[up], arr[down]};
            } else if (small > k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return vector<int>{};
    }
};

// [1, 2, 3, 5], mid = 0.5
