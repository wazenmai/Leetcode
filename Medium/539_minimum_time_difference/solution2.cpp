/**
 * Title:  Minimum Time Difference (Leetcode Medium 539)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, September, 2024
 * Method: Directly convert the time to minutes, then sort the vector.
 */

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        vector<int> v;
        for (auto& time: timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3, 2));
            v.emplace_back(h * 60 + m);
        } 
        sort(v.begin(), v.end());
        int ans = 1440 + v[0] - v[n - 1];
        for (int i = 0; i < n - 1; i++) {
            ans = min(ans, v[i + 1] - v[i]);
        }
        return ans;
    }
};
