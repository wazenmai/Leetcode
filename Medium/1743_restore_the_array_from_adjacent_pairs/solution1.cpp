/**
 * Title:  Restore the Array From Adjacent Pairs (Leetcode Medium 1743)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, November, 2023
 * Method: Graph index from 0 - n -1. Use map `encode` to map real num -> idx, `decode` to map idx to real num.
 * Result: Time complexity O(nlogn), Space complexity O(n)
 */

class Solution {
public:
    void printvec(vector<int>& v) {
        for (auto& e: v)
            cout << e << " ";
        cout << "\n";
    }
    void printmap(unordered_map<int, int>& m) {
        for (auto it = m.begin(); it != m.end(); it++) {
            cout << it->first << " " << it->second << "\n";
        }
    }
    void printgraph(vector<vector<int>>& g, int n) {
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            printvec(g[i]);
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        vector<vector<int>> graph(n);
        unordered_map<int, int> encode; // real num -> idx
        unordered_map<int, int> decode; // idx -> real num
        int num = 0;
        for (auto& pair: adjacentPairs) {
            if (encode.find(pair[0]) == encode.end()) {
                encode[pair[0]] = num;
                decode[num] = pair[0];
                num++;
            }
            if (encode.find(pair[1]) == encode.end()) {
                encode[pair[1]] = num;
                decode[num] = pair[1];
                num++;
            }
            graph[encode[pair[0]]].emplace_back(encode[pair[1]]);
            graph[encode[pair[1]]].emplace_back(encode[pair[0]]);
        }
        // printmap(encode);
        // printgraph(graph, n);
        vector<int> ans(n);
        // find left and right idx
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                temp.emplace_back(i);
            }
        }
        ans[0] = decode[temp[0]];
        ans[1] = decode[graph[temp[0]][0]];
        ans[n - 1] = decode[temp[1]];
        int last = ans[0];
        for (int i = 2; i < n - 1; i++) {
            // cout << i << ": , last=" << last << ", ";
            // printvec(ans);
            if (graph[encode[ans[i - 1]]][0] != encode[last]) {
                ans[i] = decode[graph[encode[ans[i - 1]]][0]];
            } else {
                ans[i] = decode[graph[encode[ans[i - 1]]][1]];
            }
            last = ans[i - 1];
            // printvec(ans);
        }
        return ans;
    }
};
