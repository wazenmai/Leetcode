/**
 * Title:  Minimum Speed To Arrive On Time (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, July, 2023
 * Method: Binary Search. Time Complexity O(mlogn). m is the length of dist, and n is the max spped.
 */

class Solution {
public:
    double timeRequired(vector<int>& dist, double hour, int speed) {
        double time = 0;
        int n = dist.size();
        for (int i = 0; i < n; i++) {
            double s = 1.0 * dist[i] / speed;
            if (i == n-1)
                time += s;
            else
                time += ceil(s);
        }
        return time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans = -1;
        int l = 1, r = 10000000;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (timeRequired(dist, hour, mid) <= hour) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
