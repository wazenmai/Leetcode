/**
 * Title:  Smallest Range Covering Elements from K Lists (Leetcode Hard 632)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, October, 2024
 * Method: Use binary search to find minimum range. Each time we check by iterate through every list and count number of lists that have elements in the range.
 * Result: Time complexity O(logm * m * k * n) = O(mknlogm), where m is range of numbers, k is number of lists, n is average length of list. Space complexity O(1).
 *         TLE. Since range of numbers is 1e5, nk = 3500 * 50 = 1e5, so time complexity ~~1e12.
 */

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int minimum = INT_MAX, maximum = INT_MIN;
        for (auto& num: nums) {
            minimum = min(minimum, num[0]);
            maximum = max(maximum, num.back());
        }
        // cout << "min=" << minimum << ", max=" << maximum << "\n";
        int l = 0, r = maximum - minimum + 1;
        int start = minimum;
        int range = INT_MAX;
        while (l <= r) {
            int mid = (l + r) / 2; // the length of range
            bool flag = false;
            // cout << "length: " << mid;
            for (int i = minimum; i <= maximum - mid + 1; i++) {
                int pass = 0;
                for (auto& num: nums) {
                    bool check = false;
                    for (auto& e: num) {
                        if (e >= i && e <= i + mid - 1) {
                            check = true;
                            break;
                        }
                        if (e > i + mid - 1) break;
                    }
                    if (check) pass++;
                }
                if (pass == n) {
                    if (mid < range) {
                        range = mid;
                        start = i;
                        // cout << ", update: (" << start << ", " << range << ")";
                    }
                    flag = true;
                }
            }
            // cout << ", " << flag << "\n";
            if (flag) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return vector<int>{start, start + range - 1};
    }
};

// 123
// 123
// 123

//   4 10 15 24 26
// 0  9. 12.20
//    5.    1822.  30
// 2 * 10 -> logn
