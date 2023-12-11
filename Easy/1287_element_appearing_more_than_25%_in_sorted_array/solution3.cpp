/**
 * Title:  Element Appearing More Than 25% In Sorted Array (Leetcode Easy 1287)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, December, 2023
 * Method: Binary Search. If the element appears more than 25%, then it must be in [n / 4, n / 2, 3 * n / 4].
 * Result: Time complexity: O(logn), Space complexity: O(1)
 */

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int base = n / 4;
        vector<int> candidates = {arr[n / 4], arr[n / 2], arr[3 * n / 4]};
        for (int candidate: candidates) {
            int left = lower_bound(arr.begin(), arr.end(), candidate) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), candidate) - arr.begin() - 1;
            if (right - left + 1 > base)
                return candidate;
        }
        return arr[0];
    }
};

// 11 11 12 22 33 33 44 44
// 1122 2223 3334 4555 16 / 8 = 2

// 0 | 1 || 2 | 3 || 4 | 5 || 6 |