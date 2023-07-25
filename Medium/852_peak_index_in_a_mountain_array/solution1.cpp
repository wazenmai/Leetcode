/**
 * Title:  Peak Index In A Montain Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, July, 2023
 * Method: Time complexity O(n)
 */

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int num = arr[1];
        int ans = 1;
        int n = (int)arr.size();
        for (int i = 2; i < n; i++) {
            if (num < arr[i]) {
                num = arr[i];
                ans = i;
            } else {
                break;
            }
        }
        return ans;
    }
};
