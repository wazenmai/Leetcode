/**
 * Title:  Minimum Height Trees (Leetcode Medium 310)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, Dec, 2021
 * Method: Create neighbor array then dfs - O(n^2)
 * Result: Time Limit Exceed
 */

class Solution {
private:
    vector<bool> visit;
public:
    Solution() : visit(20005, false) {}
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            vector<int> ans{0};
            return ans;
        } else if (n == 2) {
            vector<int> ans{0, 1};
            return ans;
        }
        
        vector<int> neighbor[n];
        for (auto edge: edges) {
            neighbor[edge[0]].emplace_back(edge[1]);
            neighbor[edge[1]].emplace_back(edge[0]);
        }
        
        vector<int> ans;
        int minHeight = 20005;
        
        for (int i = 0; i < n; i++) {
            int h = findHeight(n, neighbor, i);
            // cout << "node " << i << ": " << h << "\n";
            if (h < minHeight) {
                ans.clear();
                ans.emplace_back(i);
                minHeight = h;
            } else if (h == minHeight) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
    
    int findHeight(int n, vector<int>* neighbor, int s) {
        int maxHeight = 0;
        visit[s] = true;
        
        for (auto nb : neighbor[s]) {
            if (!visit[nb]){
                visit[nb] = true;
                int tempHeight = findHeight(n, neighbor, nb);
                if (tempHeight >= maxHeight)
                    maxHeight = tempHeight + 1;
                visit[nb] = false;
            }
        }
        visit[s] = false;
        return maxHeight;
    }
};