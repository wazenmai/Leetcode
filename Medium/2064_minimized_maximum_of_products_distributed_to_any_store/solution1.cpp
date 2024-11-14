/**
 * Title:  Minimized Maximum of Products Distributed to Any Store (Leetcode Medium 2064)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, November, 2024
 * Method: Binary search the answer that is the minimum of maximum products distributed to any store. [1, max(quantities)]
 * Result: Time complexity O(nlogm), space complexity O(1). m = max(quantities)
 */

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(), quantities.end());
        int m = quantities.size();
        int r = quantities[m - 1] + 1;
        int l = 1;

        function<bool(int)> check = [&](int k) {
            int store = n;
            for (int i = m - 1; i >= 0; i--) {
                store -= quantities[i] / k;
                store -= (quantities[i] % k) ? 1 : 0;
                if (store < 0) return false;
            }
            return true;
        };

        while (l < r) {
            // cout << "(" << l << "," << r << ") ";
            int mid = (l + r) >> 1;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
