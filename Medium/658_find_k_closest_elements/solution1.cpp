/**
 * Title:  Find K Closest Elements (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Mar, 2021
 */


// failed
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int size = arr.size();
        int lid = -1;
        int rid = -1;
        
        if (x <= arr[0]) {
            for (int i = 0; i < k; i++) {
                ans.emplace_back(arr[i]);
            }
            return ans;
        } else if (x >= arr[size - 1]) {
            for (int i = 0; i < k; i++) {
                ans.emplace_back(arr[i);
            }
            return ans;
        } else {
            // find x
            for (int i = 0; i < size - 1; i++) {
                if (arr[i] <= x && arr[i + 1] >= x) {
                    lid = i;
                    rid = i + 1;
                    break;
                }
            }
            for (int i = 0; i < k; i++) {
                if (x - arr[lid] < arr[rid] - x) {
                    lid--;
                } else if ((x - arr[lid] == arr[rid] - x)) {
                    lid--;
                } else {
                    rid++;
                }

            
            }
        }
    }
};
