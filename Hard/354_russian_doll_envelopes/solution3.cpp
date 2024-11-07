/**
 * Title:  Russian Doll Envelopes (Leetcode Hard 354)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, November, 2024
 * Method: Sort env[0] in ascending order, and env[1] in descending order. Then use LIS to check on env[1]. Sorting env[1] decreasing can avoid us to pick envelopes in same env[0].
 * Result: Time complexity is O(nlogn). Space complexity is O(n).
 */

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> v = {0};
        for (auto env: envelopes) {
            if (env[1] > v.back()) {
                v.emplace_back(env[1]);
            } else {
                auto it = lower_bound(v.begin(), v.end(), env[1]);
                *it = env[1];
            }
        }
        return v.size() - 1;
    }
};
