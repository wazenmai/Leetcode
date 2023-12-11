/**
 * Title:  Element Appearing More Than 25% In Sorted Array (Leetcode Easy 1287)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, December, 2023
 * Method: Brute Force
 */

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int base = n / 4;
        int times = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] == arr[i - 1]) {
                times++;
            } else {
                if (times > base) {
                    return arr[i - 1];
                }
                times = 1;
            }
        }
        if (times > base) {
            return arr[n - 1];
        }
        return arr[0];
    }
};

// 11 11 12 22 33 33 44 44
// 1122 2223 3334 4555 16 / 8 = 2

// 0 | 1 || 2 | 3 || 4 | 5 || 6 |
