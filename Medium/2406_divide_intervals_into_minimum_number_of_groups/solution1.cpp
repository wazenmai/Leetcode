/**
 * Title:  Divide Intervals Into Minimum Number of Groups (Leetcode Medium 2406)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, October, 2024
 * Method: Line sweep. Iterate the line from minimum to maximum, when interval[i]'s start meet the line, add in set. When interval[i]'s end meet the line, erase from set. The size of set is the number of groups.
 * Result: O(nlogn + m) where n is the number of intervals and m is the range of the minimum and maximum number in intervals. Space complexity O(n).
 */

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // for (auto& interval: intervals) {
        //     cout << "[" << interval[0] << "," << interval[1] << "],";
        // }
        // cout << "\n";
        int n = intervals.size();
        int maximum = intervals.back()[1];
        int minimum = intervals[0][0];
        int ans = 0;
        multiset<int> end;
        int i = 0;
        for (int line = minimum; line <= maximum; line++) {
            // cout << "line: " << line;
            while (!end.empty() && *(end.begin()) < line) {
                int old_end = *(end.begin());
                end.erase(old_end);
            }
            while (i < n && intervals[i][0] == line) {
                end.insert(intervals[i][1]);
                i++;
            }
            // cout << ", size: " << end.size() << "\n";
            ans = max(ans, (int)end.size());
        }
        return ans;
    }
};

// [1, 5] [1, 10], [2, 3], [5, 10], [6, 8]
// stack, queue, tree, sliding window, two pointer, binary search, heap, dp
// set, map
