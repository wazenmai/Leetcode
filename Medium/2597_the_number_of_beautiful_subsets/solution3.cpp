/**
 * Title:  The Number of Beautiful Subsets (Leetcode Medium 2597)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, May, 2024
 * Method: If two num's difference = k, then they have same modulo of k. So we can group all numbers by their modulo of k. Then we can calculate the number of subsets for each group.
 * Result: Time complexity is O(nlogn). Space complexity is O(n).
 */

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<vector<int>> group(k);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            group[nums[i] % k].emplace_back(nums[i]);
        }
        int ans = 1;
        for (int i = 0; i < k; i++) {
            if (group[i].size() == 0) continue;
            sort(group[i].begin(), group[i].end());
            map<int, int> m;
            for (auto& num: group[i]) {
                m[num]++;
            }
            int prev = INT_MIN;
            int prevNo = 1, prevYes = 0;
            int nowNo = 0, nowYes = 0;
            for (auto& [num, freq]: m) {
                int poss_subsets = pow(2, freq) - 1;
                nowNo = prevNo + prevYes;
                if (prev + k == num) {
                    nowYes = prevNo * poss_subsets;
                } else {
                    nowYes = (prevNo + prevYes) * poss_subsets;
                }
                prevNo = nowNo;
                prevYes = nowYes;
                prev = num;
            }
            ans *= (nowYes + nowNo);
        }
        return ans - 1;
    }
};
