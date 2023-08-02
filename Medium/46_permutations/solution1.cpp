/**
 * Title:  Permutations (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, August, 2023
 * Method: Backtracking. Time Complexity O(n x n!)
 */

class Solution {
private:
    vector<vector<int>> ans;
    int n;
public:
    void find(vector<int>& nums, vector<int>& p, vector<bool>& visit) {
        if (p.size() == n) {
            ans.emplace_back(p);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                p.emplace_back(nums[i]);
                find(nums, p, visit);
                p.pop_back();
                visit[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<bool> visit(n, false);
        for (int i = 0; i < n; i++) {
            visit[i] = true;
            vector<int> p{nums[i]};
            find(nums, p, visit);
            visit[i] = false;
        }
        return ans;
    }
};
