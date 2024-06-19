/**
 * Title:  Minimum Number of Days to Make m Bouquets(Leetcode Medium 1482)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, June, 2024
 * Method: Binary search to find the minimum day to make m bouquets. When [l, r], use l <= r and return l.
 * Result: Time complexity is O(nlogn), space complexity is O(1).
 */

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = INT_MAX, r = 0;
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;
        for (int i = 0; i < n; i++) {
            l = min(bloomDay[i], l);
            r = max(bloomDay[i], r);
        }
        int maxDay = r;
        while (l <= r) {
            int middle = (l + r) / 2;
            int shine = 0;
            int length = 0;
            for (int i = 0; i < n; i++) {
                if (bloomDay[i] <= middle) {
                    if (length == 0) {
                        length = 1;
                    } else {
                        length++;
                    }
                } else {
                    if (length >= k)
                        shine += length / k;
                    length = 0;
                }
            }
            if (length >= k) shine += length / k;
            // cout << "(" << l << "," << r << ") " << middle << " " << shine << "\n";
            if (shine < m) l = middle + 1;
            else r = middle - 1;
        }
        return l;
    }
};
