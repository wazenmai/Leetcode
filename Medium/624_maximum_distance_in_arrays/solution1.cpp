/**
 * Title:  Maximum Distance in Arrays (Leetcode Medium 624)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, August, 2024
 * Result: Time complexity is O(n), space complexity is O(1).
 */

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int total_max = -1e5, max_id = -1;
        int total_min = 1e5, min_id = -1;
        for (int i = 0; i < n; i++) {
            if (arrays[i].front() < total_min) {
                total_min = arrays[i].front();
                min_id = i;
            }
            if (arrays[i].back() > total_max) {
                total_max = arrays[i].back();
                max_id = i;
            }
        }
        if (min_id != max_id) return total_max - total_min;
        // fix max and find other min v.s. fix min and find other max
        int temp_min = 1e5, temp_max = -1e5;
        for (int i = 0; i < n; i++) {
            if (i == min_id) continue;
            temp_min = min(temp_min, arrays[i].front());
            temp_max = max(temp_max, arrays[i].back());
        }
        return max(total_max - temp_min, temp_max - total_min);
    }
};
