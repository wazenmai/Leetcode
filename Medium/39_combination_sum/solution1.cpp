/**
 * Title:  Combination Sum (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, Feb, 2022
 */


class Solution {
private:
    vector<vector<int>> ans;
    int tg;
    int n;
public:
    void findNum(vector<int>& combination, vector<int>& candidates, int index, int temp_sum) {
        temp_sum += candidates[index];
        
        if (temp_sum == tg) {
            combination.emplace_back(candidates[index]);
            ans.emplace_back(combination);
            temp_sum -= candidates[index];
            combination.pop_back();
            return;
        } else if (temp_sum > tg) {
            temp_sum -= candidates[index];
            return;
        } else { // temp_sum < tg
            combination.emplace_back(candidates[index]);
            for (int j = index; j < n; j++) {
                if (candidates[j] > tg)
                    break;
                findNum(combination, candidates, j, temp_sum);
            }
            combination.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        n = (int)candidates.size();
        tg = target;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < n; i++) {
            if (candidates[i] > target)
                break;
            findNum(combination, candidates, i, 0);
            combination.clear();
        }
        return ans;
    }
};
