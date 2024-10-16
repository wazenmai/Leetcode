/**
 * Title:  Longest Happy String (Leetcode Medium 1405)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, October, 2024
 * Method: Optimize and tidy the code.
 * Result: Time complexity is O(a + b + c), Space complexity is O(1).
 */

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // 1. Make a vector that store (cnt, char) non-decreasing
        vector<pair<int, char>> temp; // (cnt, char)
        temp.emplace_back(make_pair(a, 'a'));
        temp.emplace_back(make_pair(b, 'b'));
        temp.emplace_back(make_pair(c, 'c'));
        sort(temp.begin(), temp.end(), greater<pair<int, char>>());

        // 2. Make a vector that store the times to put one char and two chars
        vector<vector<int>> cnt(3, vector<int>(2, 0)); // (time for one char, time for two chars)
        // max element
        cnt[0][1] = temp[0].first / 2;
        cnt[0][0] = temp[0].first & 1;
        int space = (temp[0].first + 1) / 2 - 1;
        // the rest two element
        if (temp[1].first / 2 + temp[2].first / 2 >= space) {
            for (int i = 1; i <= 2; i++) {
                cnt[i][1] = temp[i].first / 2;
                cnt[i][0] = temp[i].first & 1;
            }
        } else {
            if (temp[1].first + temp[2].first < space) {
                cnt[1][0] = temp[1].first;
                cnt[2][0] = temp[2].first;
            } else {
                cnt[2][0] = temp[2].first;
                space -= temp[2].first;
                int t = 2 * (temp[1].first - space);
                cnt[1][1] = t / 2;
                if (cnt[1][1] * 2 > temp[1].first) {
                    cnt[1][1]--;
                }
                cnt[1][0] = temp[1].first - cnt[1][1] * 2;
            }
        }

        // 3. Start the loop to concat string
        int cur = 0;
        string s = "";
        while (true) {
            // add string
            if (cnt[cur][1] > 0) {
                s += temp[cur].second;
                s += temp[cur].second;
                cnt[cur][1]--;
            } else if (cnt[cur][0] > 0) {
                s += temp[cur].second;
                cnt[cur][0]--;
            } else {
                break;
            }
            // find next char, but not the same with cur
            char last_char = cur;
            int times = -1;
            for (int i = 0; i < 3; i++) {
                if (i == last_char) continue;
                if (cnt[i][0] + cnt[i][1] > times) {
                    times = cnt[i][0] + cnt[i][1];
                    cur = i;
                }
            }
        }
        return s;
    }
};
