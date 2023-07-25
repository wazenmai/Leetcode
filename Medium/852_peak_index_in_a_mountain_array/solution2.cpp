/**
 * Title:  Peak Index In A Montain Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, July, 2023
 * Method: Time complexity O(log(n))
 */

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = (int)arr.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr[mid] > arr[mid + 1]) {
                r = mid;
            } else if (arr[mid] < arr[mid + 1]) {
                l = mid + 1;
            }
        }
        return l;
    }
};
