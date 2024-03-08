/**
 * Title:  Count Elements With Maximum Frequency (Leetcode Easy 3005)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, March, 2024
 */

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int max_f = 0;
        unordered_map<int, int> m;
        for (auto& num: nums) {
            m[num]++;
            max_f = max(max_f, m[num]);
        }
        int ans = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == max_f) {
                ans += max_f;
            }
        }
        return ans;
    }
};
