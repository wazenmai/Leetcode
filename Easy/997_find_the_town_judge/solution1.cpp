/**
 * Title:  Find the Town Judge (Leetcode Easy 997)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, Jan, 2022
 * Method: O(n) - Find node that its indegree = n -1, outdegree = 0
 */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int indegree[1002] = {0};
        int outdegree[1002] = {0};
        for (auto& t: trust) {
            outdegree[t[0]]++;
            indegree[t[1]]++;
        }
        
        int judge = -1;
        int judge_count = 0;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                judge_count++;
                judge = i;
            }
        }
        if (judge_count == 1)
            return judge;
        return -1;
    }
};
