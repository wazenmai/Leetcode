/**
 * Title:  Top K Frequent Elements (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, April, 2022
 * Method: Max Heap
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
        priority_queue<pair<int, int>> pq;
        for (auto& k : ht)
            pq.push(make_pair(k.second, k.first));
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.emplace_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
