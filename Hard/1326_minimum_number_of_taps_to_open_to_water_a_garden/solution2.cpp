/**
 * Title:  Minimum Number of Taps to Open to Water a Garden (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   31, August, 2023
 * Method: Greedy. First calculate max_reach end of each start position. Then greedy take the max end. Time complexity O(n)
 */

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> max_reach(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            int start = (i - ranges[i] > 0) ? i - ranges[i] : 0;
            int end = (i + ranges[i] < n) ? i + ranges[i] : n;
            max_reach[start] = max(max_reach[start], end); 
        }
        int taps = 0;
        int last_end = 0;
        int cur_end = 0; // watered garden(0 ~ end)
        while (cur_end < n) {
            taps++;
            int next_end = 0;
            for (int j = last_end; j <= cur_end; j++) {
                next_end = max(max_reach[j], next_end);
            }
            if (next_end == 0 || next_end == cur_end)
                break;
            last_end = cur_end;
            cur_end = next_end;
        }
        if (cur_end == n)
            return taps;
        return -1;
    }
};
