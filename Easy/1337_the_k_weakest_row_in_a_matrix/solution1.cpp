/**
 * Title:  The K Weakest Row in a Matrix (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, Mar, 2022
 */

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = (int)mat.size();
        int n = (int)mat[0].size();
        vector<vector<int>> soldiers(m, vector(2, 0));
        for (int i = 0; i < m; i++) {
            soldiers[i][1] = i;
            for (int j = 0; j < n; j++)
                soldiers[i][0] += mat[i][j];
        }
        sort(soldiers.begin(), soldiers.end(), compare);
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.emplace_back(soldiers[i][1]);
        return ans;
    }
};
