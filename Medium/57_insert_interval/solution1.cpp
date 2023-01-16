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
        vector<int> covered;
        if (n == 0) {
            intervals.emplace_back(newInterval);
            return intervals;
        } 
        // collect covered intervals
        for (int i = 0; i < n; i++) {
            if (newInterval[0] <= intervals[i][0] && newInterval[1] >= intervals[i][0]) { // left covered
                covered.emplace_back(i);
            } else if (newInterval[1] >= intervals[i][1] && newInterval[0] <= intervals[i][1]) { // right covered
                covered.emplace_back(i);
            }
            // no covered
            if (newInterval[0] > intervals[i][1])
                start = i;
            if (newInterval[1] < intervals[i][0])
                end = i;
            if (newInterval[0] >= intervals[i][0] && newInterval[1] <= intervals[i][1]) // inside
                return intervals;
        }
        cout << "no cover: " << start << " " << end << "\n";
        cout << "covered: ";
        for (auto& v: covered) {
            cout << v << ", ";
        }
        cout << "\n";
        if (covered.empty()) { // no covered
            if (start == -1 && end == -1) {
                return intervals;
            } else if (start == -1) {
                vector<int> v = intervals[n - 1];
                for (int i = n - 1; i > 0; i--) {
                    intervals[i] = intervals[i - 1];
                }
                intervals[0] = newInterval;
                intervals.emplace_back(v);  
            } else if (end == -1) {
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
        } else {
            int m = covered.size();
            newInterval[0] = min(newInterval[0], intervals[covered[0]][0]);
            newInterval[1] = max(newInterval[1], intervals[covered[m - 1]][1]);
            int d = covered[m - 1] - covered[0];
            intervals[covered[0]] = newInterval;
            vector<int> temp = intervals[n - 1];
            for (int i = covered[0] + 1; i < n - d; i++) {
                intervals[i] = intervals[i + d];
            }
            while (d--) {
                intervals.pop_back();
            }
        }
        return intervals;
    }
};
