/**
 * Title:  Element Appearing More Than 25% In Sorted Array (Leetcode Easy 1287)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, December, 2023
 * Method: If the element appears more than 25% and at i index, then i + n / 4 index must be the same
 */

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int base = n / 4;
        for (int i = 0; i < n; i++) {
            if (arr[i] == arr[i + base]) {
                return arr[i];
            }
        }
        return arr[0];
    }
};

// 11 11 12 22 33 33 44 44
// 1122 2223 3334 4555 16 / 8 = 2

// 0 | 1 || 2 | 3 || 4 | 5 || 6 |