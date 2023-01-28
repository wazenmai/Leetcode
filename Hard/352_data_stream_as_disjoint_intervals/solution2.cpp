/**
 * Title:  Data Stream a Disjoint Intervals (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, Janurary, 2023
 * Method: Use left and right to maintain disjoint intervals.
 * Result: Time O(logN) for addNum, O(N) for getIntervals. Space O(N).
 */

class SummaryRanges {
private:
    map<int, int> intervals;
public:
    SummaryRanges() {}

    void addNum(int value) {
        int left = value, right = value;
        auto small_interval = intervals.upper_bound(value);
        // extend left value
        if (small_interval != intervals.begin()) {
            auto max_interval = small_interval;
            --max_interval;
            if (max_interval->second >= value) // included in max_interval
                return;
            if (max_interval->second == value - 1) {
                left = max_interval->first;
            }
        }
        // extend right value -> merge
        if (small_interval != intervals.end() && small_interval->first == value + 1) {
            right = small_interval->second;
            intervals.erase(small_interval);
        }
        intervals[left] = right;

    }
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for (auto& p: intervals) {
            ans.emplace_back(vector<int>{p.first, p.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
