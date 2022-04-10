/**
 * Title:  Top K Frequent Elements (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, April, 2022
 */

class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ht;
        for (auto& x : nums)
            ht[x]++;
        vector<pair<int, int>> v;
        for (auto& k : ht) {
            v.emplace_back(make_pair(k.second, k.first));
        }
        sort(v.begin(), v.end(), compare);
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.emplace_back(v[i].second);
        return ans;
    }
};
