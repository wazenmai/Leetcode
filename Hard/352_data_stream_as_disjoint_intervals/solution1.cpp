/**
 * Title:  Data Stream a Disjoint Intervals (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   28, Janurary, 2023
 * Method: Use left and right to maintain disjoint intervals.
 * Result: Time O(log(N)) for addNum, O(N) for getIntervals. Space O(N).
 */

class SummaryRanges {
private:
    set<int> nums;
public:
    SummaryRanges() {}
    
    void addNum(int value) {
        nums.insert(value);
    }
    vector<vector<int>> getIntervals() {
        if (nums.empty())
            return {};
        vector<vector<int>> intervals;
        int left = -1, right = -1;
        for (int num: nums) {
            if (left < 0) {
                left = right = num;
            } else if (num == right + 1) {
                right = num;
            } else {
                intervals.emplace_back({left, right});
                left = right = num;
            }
        }
        intervals.emplace_back({left, right});
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
