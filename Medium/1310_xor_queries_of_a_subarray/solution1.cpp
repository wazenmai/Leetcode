/**
 * Title:  XOR Queries of a Subarray (Leetcode Medium 1310)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, September, 2024
 * Method: XOR also has prefix sum property.
 */


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        vector<int> ans;
        for (auto& query: queries) {
            ans.emplace_back(prefix[query[1] + 1] ^ prefix[query[0]]);
        }
        return ans;
    }
};
