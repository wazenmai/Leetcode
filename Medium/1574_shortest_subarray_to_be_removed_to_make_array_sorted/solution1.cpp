/**
 * Title:  Shortest Subarray to be Removed to Make Array Sorted (Leetcode Medium 1574)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, November, 2024
 * Method: Since we can only remove subarray ("continuous"), we need to find non-decreasing subarray arr[:l] and arr[r:] first.
 *         Then iterate through l ~ 0, find the fist value in (r ~ n - 1) >= arr[l], and update the length.
 * Result: Time complexity O(nlogn), space complexity O(1).
 */

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;
        // find sorted arr[:l], arr[r:]
        while (l + 1 < n && arr[l + 1] >= arr[l]) l++;
        while (r >= 1 && arr[r - 1] <= arr[r]) r--;
        // Early answer return
        if (r == 0) return 0; // this array is non-decreasing
        if (arr[r] >= arr[l]) return r - l - 1; // combine arr[:l] and arr[r:]
        if (l == 0 && r == n - 1) return n - 1; // this array is non-increasing
        
        function<int(int, int)> bs = [&](int lb, int v) {
            int rb = n;
            while (lb < rb) {
                int mid = (lb + rb) >> 1;
                if (arr[mid] >= v) {
                    rb = mid;
                } else {
                    lb = mid + 1;
                }
            }
            return lb;
        };
        
        int len = max(l + 1, n - r);
        for (int left = l; left >= 0; left--) {
            int id = bs(r, arr[left]);
            if (id == n) continue;
            len = max(len, left + 1 + n - id);
        }
        return n - len;
    }
};
// remove subarray ("continuous")
// 1,2,3,10,4,2,3,5
// 1,2,3,10
// 2,3,5

// 4
// 1,2,3

// 0. 1. 2 3 4. 5. 6. 7  8 9. 10
// 13,0,14,7,18,18,18,16,8,15,20
