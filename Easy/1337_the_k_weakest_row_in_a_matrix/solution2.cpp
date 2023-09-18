/**
 * Title:  The K Weakest Row in a Matrix (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, September, 2023
 * Method: Use vector of pairs to sort the strength of each row. O(mn + nlogn)
 */

class Solution {
private:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    void printvec(vector<pair<int, int>>& v) {
        for (auto& p: v) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << "\n";
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<pair<int, int>> v(rows);
        for (int i = 0; i < rows; i++) {
            int soldiers = 0;
            for (int j = 0; j < cols; j++) {
                if (mat[i][j] == 1) {
                    soldiers++;
                }
            }
            v[i] = make_pair(soldiers, i);
        }
        sort(v.begin(), v.end(), compare);
        // printvec(v);
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.emplace_back(v[i].second);
        }
        return ans;
    }
};