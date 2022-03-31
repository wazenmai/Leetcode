/**
 * Title:  Split Array Largest Sum (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, Mar, 2022
 */

class Solution {
public:
    int bs(vector<int>& nums, int m, int l, int r) {
        if (l >= r)
            return r;
        int mid = l / 2 + r / 2;
        // cout << "bs: " << mid << "\n";
        int cut = 0;
        long long sum = 0;
        for (auto& x : nums) {
            if (x > mid)
                return bs(nums, m, mid + 1, r);
            sum += x;
            if (sum == mid) {
                cut++;
                sum = 0;
            }
            if (sum > mid) {
                cut++;
                sum = x;
            }
        }
        if (sum > 0)
            cut++;
        if (cut > m)
            return bs(nums, m, mid + 1, r);
        return bs(nums, m, l, mid);
    }

    int splitArray(vector<int>& nums, int m) {
        return bs(nums, m, 0, 2147483647);
    }
};
