/**
 * Title:  Nondecreasing Subsequences (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, Janurary, 2023
 */

class Solution {
private:
    vector<vector<int>> ans;
    set<vector<int>> us;
    int n;
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        for (int i = 0; i < n - 1; i++) {
            recursion(-101, i, temp, nums);
            temp.clear();
        }
        return ans;
    }

    void recursion(int prev, int id, vector<int>& subsq, vector<int>& nums) {
        if (prev > nums[id])
            return;
        subsq.emplace_back(nums[id]);
        if (subsq.size() >= 2) {
            if (us.find(subsq) == us.end()) {
                us.insert(subsq);
                ans.emplace_back(subsq);
            }
        }
        for (int i = id + 1; i < n; i++) {
            if (nums[i] >= nums[id])
                recursion(nums[id], i, subsq, nums);
        }
        subsq.pop_back();
    }
};
