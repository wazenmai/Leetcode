/**
 * Title:  Find K Closest Elements (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Mar, 2021
 */

// binary search
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int size = arr.size();
        int lid = 0;
        int rid = size - k;

        while (lid < rid) {
            int mid = (lid + rid) / 2;
            if (x - arr[mid] > arr[mid + k] - x)
                lid = mid + 1;
            else
                rid = mid;
        }
        while (k--) {
            ans.emplace_back(arr[lid]);
            lid++;
        }
        return ans;
    }
};
