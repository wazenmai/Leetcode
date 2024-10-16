/**
 * Title:  Longest Happy String (Leetcode Medium 1405)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, October, 2024
 * Method: Use a vector to store the number of each character, and then sort it. Use another vector to store the number of concat one char and two chars for each character. Concat the string according to the number of each character, make sure next character is not the same as the current character.
 * Result: Time complexity is O(a + b + c), Space complexity is O(1).
 */

class Solution {
public:
    static bool compare(pair<int, char>& x, pair<int, char>& y) {
        return x > y;
    }
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> temp; // (cnt, char)
        temp.emplace_back(make_pair(a, 'a'));
        temp.emplace_back(make_pair(b, 'b'));
        temp.emplace_back(make_pair(c, 'c'));
        sort(temp.begin(), temp.end(), compare);
        vector<vector<int>> cnt(3, vector<int>(2, 0)); // (time for one char, time for two chars)
        // max element
        cnt[0][1] = temp[0].first / 2;
        cnt[0][0] = temp[0].first % 2;
        int space = (temp[0].first + 1) / 2 - 1;
        // the rest two element
        if (temp[1].first / 2 + temp[2].first / 2 >= space) {
            for (int i = 1; i <= 2; i++) {
                cnt[i][1] = temp[i].first / 2;
                cnt[i][0] = temp[i].first % 2;
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

// 21, 5, 4 -> 10, 2, 2
// space = 10
// 21, 10, 4 -> 10, 5, 2
// space = 11 -> 6, 10
// x
// t / 2 + (x - t) = 6

// t / 2 - t = 6 - x
// t - t / 2 = 5
// t = 2 * 5 = 10

// 5, 3, 1 -> 2, 1, 0, space = 2
// space = 1, 3
// t / 2 + (3 - t) = 1
// t/2 = 2
