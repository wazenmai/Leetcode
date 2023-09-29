/**
 * Title:  Monotonic Array (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, September, 2023
 * Method: Speed optimization. Use faster io and check init and comp in one loop.
 */

// Let things go faster in io
static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isMonotonic(vector<int> &nums) {
        bool init = false;
        bool inc;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                continue;

            bool comp = nums[i] > nums[i - 1];
            if (!init) {
                init = true;
                inc = comp;
            } else if (inc != comp)
                return false;
        }

        return true;
    }
};
