/**
 * Title:  Ugly Number II (Leetcode Medium 264)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, August, 2024
 * Method: Use three pointers to store the index of the smallest number to multiple 2, 3, 5.
 * Result: Time complexity is O(n), space complexity is O(n).
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n);
        int i2 = 0, i3 = 0, i5 = 0; // index of smallest number to multiple 2, 3, 5
        v[0] = 1;
        for (int i = 1; i < n; i++) {
            int ug2 = v[i2] * 2;
            int ug3 = v[i3] * 3;
            int ug5 = v[i5] * 5;
            int minug = min(ug2, min(ug3, ug5));
            v[i] = minug;
            if (ug2 == minug) i2++;
            if (ug3 == minug) i3++;
            if (ug5 == minug) i5++;
        }
        return v[n - 1];
    }
};
