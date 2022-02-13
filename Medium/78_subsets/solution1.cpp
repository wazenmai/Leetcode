/**
 * Title:  Subsets (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, Feb, 2022
 */

class Solution {
public:
    void print_double_vec(vector<vector<int>>& vecs) {
        cout << "\n===DOUBLE VEC===\n";
        for (auto& vec: vecs) {
            print_vec(vec);
        }
    }
    void print_vec(vector<int>& vec) {
        cout << '[';
        for (auto& x : vec)
            cout << x << " ";
        cout << "], ";
    }
    void find_subsets(vector<vector<int>>& subset_nums, int num) {
        if (!subset_nums.empty()) {
            int m = (int)subset_nums.size();
            for (int j = 0; j < m; j++) {
                auto temp = subset_nums[j];
                temp.emplace_back(num);
                subset_nums.emplace_back(temp);
            }
        }
        vector<int> one_num(1, num);
        subset_nums.emplace_back(one_num);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            find_subsets(ans, nums[i]);
            // print_double_vec(ans);
        }
        vector<int> temp(0);
        ans.emplace_back(temp);
        return ans;
    }
};
