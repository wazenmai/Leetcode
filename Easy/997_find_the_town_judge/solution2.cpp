/**
 * Title:  Find the Town Judge (Leetcode Easy 997)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, February, 2022
 * Method: O(n) - Find node that its indegree = n -1, outdegree = 0
 */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1, 0);
        vector<int> out(n + 1, 0);
        for (auto& pair: trust) {
            out[pair[0]]++;
            in[pair[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (in[i] == n - 1 && out[i] == 0)
                return i;
        }
        return -1;
    }
};
