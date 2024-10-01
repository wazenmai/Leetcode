/**
 * Title:  Check If Array Pairs Are Divisible by k (Leetcode Medium 1497)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, October, 2024
 */

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            arr[i] %= k;
            if (arr[i] < 0) {
                arr[i] += k;
            }
        }
        sort(arr.begin(), arr.end());
        // for (auto& v: arr) {
        //     cout << v << ",";
        // }
        // cout << "\n";
        int l = 0, r = n - 1;
        while (l < r) {
            if (arr[l] == 0 && arr[l + 1] == 0) {
                l += 2;
            } else if (arr[l] + arr[r] == k) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
};
