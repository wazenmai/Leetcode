/**
 * Title:  Sum of Prefix Scores of Strings (Leetcode Hard 2416)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, September, 2024
 * Result: TLE.
 */

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<string, int> m;
        for (auto word: words) {
            string temp = "";
            for (const char& c: word) {
                temp += c;
                m[temp]++;
            }
        }
        vector<int> ans;
        for (auto word: words) {
            string temp = "";
            int cnt = 0;
            for (const char& c: word) {
                temp += c;
                cnt += m[temp];
            }
            ans.emplace_back(cnt);
        }
        return ans;
    }
};
