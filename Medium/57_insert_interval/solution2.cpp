/**
 * Title:  Insert Interval (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, Janurary, 2023
 */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int start = -1, end = -1;
        int cover_start = n, cover_end = 0;
        if (n == 0) {
            intervals.emplace_back(newInterval);
            return intervals;
        } 
        // collect covered intervals
        for (int i = 0; i < n; i++) {
            if (newInterval[0] <= intervals[i][0] && newInterval[1] >= intervals[i][0]) { // left covered
                cover_start = min(cover_start, i);
                cover_end = max(cover_end, i);
            } else if (newInterval[1] >= intervals[i][1] && newInterval[0] <= intervals[i][1]) { // right covered
                cover_start = min(cover_start, i);
                cover_end = max(cover_end, i);
            }
            // no covered
            if (newInterval[0] > intervals[i][1]) // not at the beginning
                start = i;
            if (newInterval[1] < intervals[i][0]) // not at the end
                end = i;
            if (newInterval[0] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) // inside interval
                return intervals;
        }
        // cout << "no cover: " << start << " " << end << "\n";
        // cout << "covered: ";
        // for (auto& v: covered) {
        //     cout << v << ", ";
        // }
        // cout << "\n";
        if (cover_start == n) { // no covered
            if (start == -1 && end == -1) {
                return intervals;
            } else if (start == -1) { // at the beginning
                vector<int> v = intervals[n - 1];
                for (int i = n - 1; i > 0; i--) {
                    intervals[i] = intervals[i - 1];
                }
                intervals[0] = newInterval;
                intervals.emplace_back(v);  
            } else if (end == -1) { // at the end
                intervals.emplace_back(newInterval);
            } else {
                vector<int> v = intervals[start + 1];
                intervals[start + 1] = newInterval;
                for (int i = start + 2; i < n; i++) {
                    vector<int> temp = intervals[i];
                    intervals[i] = v;
                    v = temp;
                }
                intervals.emplace_back(v);
            }
        } else { // covered
            int d = cover_end - cover_start;
            newInterval[0] = min(newInterval[0], intervals[cover_start][0]);
            newInterval[1] = max(newInterval[1], intervals[cover_end][1]);
            intervals[cover_start] = newInterval;
            vector<int> temp = intervals[n - 1];
            for (int i = cover_start + 1; i < n - d; i++) {
                intervals[i] = intervals[i + d];
            }
            while (d--) {
                intervals.pop_back();
            }
        }
        return intervals;
    }
};
