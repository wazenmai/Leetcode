/**
 * Title:  Russian Doll Envelopes (Leetcode Hard 354)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, November, 2024
 * Method: Coding optimization. Use lambda function to replace compare function. Use binary search to replace lower_bound.
 * Result: Time complexity is O(nlogn). Space complexity is O(n).
 */

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            return (a[0] == b[0]) ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> v = {0};
        
        function<int(int)> bs = [&](int val) {
            int l = 0, r = v.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (v[mid] >= val) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            return l;
        };
        
        for (auto env: envelopes) {
            if (env[1] > v.back()) {
                v.emplace_back(env[1]);
            } else {
                int i = bs(env[1]);
                v[i] = env[1];
            }
        }
        return v.size() - 1;
    }
};
