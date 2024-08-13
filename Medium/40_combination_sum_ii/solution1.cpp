/**
 * Title:  Combination Sum II (Leetcode Medium 40)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, August, 2024
 * Method: Use map to store frequency of each number. Then use backtracking to find all possible combinations.
 * Result: Time complexity is O(2^n), space complexity is O(n).
 */

class Solution {
private:
    set<vector<int>> res;
    map<int, int> m;
    int n;
public:
    void print(vector<int>& v) {
        cout << "[";
        for (auto& num: v) {
            cout << num << ",";
        }
        cout << "]";
    }
    void combination(vector<int>& nums, int target, int i, vector<int>& cur, int s) {
        if (s > target) return;
        if (s == target) {
            vector<int> temp = cur;
            sort(temp.begin(), temp.end());
            res.insert(temp);
            return;
        }
        if (i == n) return;
        // choose
        int cnt = m[nums[i]];
        int cut = cnt;
        // cout << i << ": " << cnt << "->";
        for (int k = 1; k <= cnt; k++) {
            cur.emplace_back(nums[i]);
            s += nums[i];
            // cout << "(";
            // print(cur);
            // cout << ", " << s << ")\n";
            if (s > target) {
                cut = k;
                break;
            }
            combination(nums, target, i + 1, cur, s);
        }
        for (int k = 1; k <= cut; k++) {
            cur.pop_back();
            s -= nums[i];
        }
        // not choose
        // cout << i << ": no=";
        // print(cur);
        // cout << ", " << s << "\n";
        combination(nums, target, i + 1, cur, s);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (auto& num: candidates) {
            m[num]++;
        }
        vector<int> nums;
        for (auto it = m.begin(); it != m.end(); it++) {
            nums.emplace_back(it->first);
        }
        // print(nums);
        // cout << "\n";
        n = nums.size();
        vector<int> cur;
        combination(nums, target, 0, cur, 0);
        vector<vector<int>> ans;
        for (auto& v: res) {
            ans.emplace_back(v);
        }
        return ans;
    }
};
