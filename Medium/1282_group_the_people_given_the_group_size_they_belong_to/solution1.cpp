/**
 * Title:  Group the People Given the Group Size They Belong To (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, September, 2023
 * Method: Time complexity O(n), Space complexity O(n).
 */

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> m;
        int n = groupSizes.size();
        for (int i = 0; i < n; i++) {
            if (m.find(groupSizes[i]) != m.end()) {
                m[groupSizes[i]].emplace_back(i);
            } else {
                m[groupSizes[i]] = vector<int>{i};
            }
        }
        
        vector<vector<int>> ans;
        for (auto it = m.begin(); it != m.end(); it++) {
            vector<int> temp;
            for (int e: it->second) {
                temp.emplace_back(e);
                if (temp.size() == it->first) {
                    ans.emplace_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};
