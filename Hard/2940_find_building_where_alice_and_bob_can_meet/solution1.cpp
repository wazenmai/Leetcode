/**
 * Title:  Find Building Where Alice and Bob Can Meet (Leetcode Medium 1497)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, December, 2024
 * Method: Brute Force with unordered_map to store the repetitive query. Use long long to encode the query, smaller query id in the front: q1 * 2^16 + q2.
 * Result: Time complexity O(mn), Space complexity O(m). m is the number of queries, n is the number of buildings.
 */

class Solution {
public:
    vector<int> leftmostBuildingQueries(const vector<int>& heights, const vector<vector<int>>& queries) {
        vector<int> ans;
        int n = heights.size();
        unordered_map<long long, int> m;
        for (const auto& q: queries) {
            int q1 = (q[0] < q[1]) ? q[0] : q[1]; // small index
            int q2 = (q[0] < q[1]) ? q[1] : q[0]; // large index
            if (q1 == q2) {
                ans.emplace_back(q1);
                continue;
            } else if (heights[q2] > heights[q1]) {
                ans.emplace_back(q2);
                continue;
            }
            long long check = ((long long)(q1 + 1) * (1 << 16)) + (q2 + 1);
            if (m.find(check) != m.end()) {
                ans.emplace_back(m[check]);
                continue;
            }
            int max_h = max(heights[q1], heights[q2]);
            int max_id = q2;
            int ans_id = -1;
            for (int i = max_id; i < n; i++) {
                if (heights[i] > max_h) {
                    ans_id = i;
                    break;
                }
            }
            m[check] = ans_id;
            ans.emplace_back(ans_id);
        }
        return ans;
    }
};
// 1. n^2

// 0          1         2        3         4           5         6        7         8         9            10      11       12        13        14         15        16        17        18        19          20      21        22       23       24       25
// [114165760,539345442,81139102,627045938,859457649,657089945,407107076,224498752,873581347,577863951,588300794,780383776,869894231,577492660,510103030,712066345,831864555,180321648,661054641,188666633,531792875,637117214,468185630,7626673,910050349,902414591,585841010,582530343,274641025,525619441,593261130,747308271,405096997,556806166,913998409,950563081,657951184,488747164,994153682,771016447,34273538,623734,632192298,211517479,20281855,330922425,583460285,742527431,160360124,277893081,697158115,529400454,731881715,858248560,348454861,322896681,100439359,304708231,755323274,540589534,465746985,458149995,731367959,879754706,555159153]
// 627045938
// 531792875, 
// 910050349
