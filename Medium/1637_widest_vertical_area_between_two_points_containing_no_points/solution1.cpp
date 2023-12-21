/**
 * Title:  Widest Vertical Area Between Two Points Containing No Points (Leetcode Medium 1637)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, December, 2023
 * Method: Set sorting.
 * Result: Time complexity O(nlogn), Space complexity O(n)
 */

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> s;
        for (auto& point: points) {
            s.insert(point[0]);
        }
        int diff = 0;
        int last = *(s.begin());
        for (auto it = s.begin(); it != s.end(); it++) {
            diff = max(*it - last, diff);
            last = *it;
        }
        return diff;
    }
};
