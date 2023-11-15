/**
 * Title:  Maximum Element After Decreasing and Rearranging (Leetcode Medium 1846)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, November, 2023
 * Result: Time Complexity O(nlogn)
 */

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        if (arr[0] != 1) return n;
        
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] <= 1) continue;
            arr[i] = arr[i - 1] + 1;
        }
        return arr[n - 1];
    }
};
