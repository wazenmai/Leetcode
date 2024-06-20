/**
 * Title:  Magnetic Force Between Two Balls (Leetcode Medium 1552)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, June, 2024
 * Method: Binary search to find the maximum distance between two balls. When [l, r], use l <= r and return r.
 * Result: Time complexity is O(nlogn + nlogm), space complexity is O(1).
 */

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int r = position[n - 1] - position[0];
        int l = 1;
        if (m == 2) return r;
        while (l <= r) {
            int mid = (l + r) / 2;
            int last = -1e9;
            int ball = 0;
            for (int i = 0; i < n; i++) {
                if (position[i] - last >= mid) {
                    ball++;
                    last = position[i];
                }
            }
            // cout << "(" << l << "," << r << "): " << mid << " " << ball << "\n";
            if (ball >= m) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};
