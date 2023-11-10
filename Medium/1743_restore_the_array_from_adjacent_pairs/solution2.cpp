/**
 * Title:  Restore the Array From Adjacent Pairs (Leetcode Medium 1743)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, November, 2023
 * Method: Reduce space to only one unordered_map as graph.
 * Result: Time complexity O(nlogn), Space complexity O(n)
 */

class Solution {
public:
    void printvec(vector<int>& v) {
        for (auto& e: v)
            cout << e << " ";
        cout << "\n";
    }
    void printgraph(unordered_map<int, vector<int>>& g) {
        for (auto it = g.begin(); it != g.end(); it++) {
            cout << it->first << ": ";
            printvec(it->second);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        unordered_map<int, vector<int>> g;
        for (auto& p: adjacentPairs) {
            g[p[0]].emplace_back(p[1]);
            g[p[1]].emplace_back(p[0]);
        }

        vector<int> ans(n, -1000000);
        for (auto it = g.begin(); it != g.end(); it++) {
            if (it->second.size() == 1) {
                if (ans[0] != -1000000) {
                    ans[n - 1] = it->first;
                    break;
                } else {
                    ans[0] = it->first;
                }
            }
        }
        // printvec(ans);
        // printgraph(g);

        ans[1] = g[ans[0]][0];
        int last = ans[0];
        for (int i = 2; i < n - 1; i++) {
            if (g[ans[i - 1]][0] != last) {
                ans[i] = g[ans[i - 1]][0];
            } else {
                ans[i] = g[ans[i - 1]][1];
            }
            last = ans[i - 1];
        }
        return ans;
    }
};
