/**
 * Title:  Valid Mountain Array (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, Jan, 2022
 */

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = (int)arr.size();
        if (n < 3)
            return false;
        int slide = -1;
        for (int i = 1; i < n; i++) {
            if (slide == 0) {
                if (arr[i] > arr[i - 1])
                    continue;
                if (arr[i] == arr[i - 1])
                    return false;
                slide = 1;
            } else if (slide > 0) {
                if (arr[i] >= arr[i - 1])
                    return false;
            } else {
                if (arr[i] <= arr[i - 1])
                    return false;
                slide = 0;
            }
        }
        return (slide > 0) ? true : false;
    }
};
