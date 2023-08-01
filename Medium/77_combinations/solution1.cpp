/**
 * Title:  Combinations (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   01, August, 2023
 */

class Solution {
public:
    void comb(vector<vector<int>>& ans, vector<int>& num, int start, int end, int k, int o) {
        // o: # of elements in num
        if (o == k) {
            ans.emplace_back(num);
            return;
        }
        for (int i = start; i <= end && end - i + 1 >= k - o; i++) {
            num.emplace_back(i);
            comb(ans, num, i + 1, end, k, o + 1);
            num.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> num;
        comb(ans, num, 1, n, k, 0);
        return ans;
    }
};
