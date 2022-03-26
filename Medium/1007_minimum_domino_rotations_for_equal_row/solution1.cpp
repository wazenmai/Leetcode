/**
 * Title:  Minimum Domino Rotations for Equal Row (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, Mar, 2022
 */

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<bool> check(6, true);
        vector<pair<int, int>> count(6, make_pair(0, 0));
        vector<int> same(6, 0);
        int n = (int)tops.size();
        for (int i = 0; i < n; i++) {
            count[tops[i] - 1].first += 1;
            count[bottoms[i] - 1].second += 1;
            if (tops[i] == bottoms[i])
                same[tops[i] - 1]++;
            for (int j = 0; j < 6; j++) {
                if (check[j] == false)
                    continue;
                if (tops[i] != j + 1 && bottoms[i] != j + 1)
                    check[j] = false;
            }
        }
        bool flag = false;
        for (int i = 0; i < 6; i++) {
            if (check[i])
                flag = true;
        }
        if (!flag)
            return -1;
        int min_rotate = 20001;
        for (int i = 0; i < 6; i++) {
            if (check[i]) {
                if (count[i].first > count[i].second) {
                    min_rotate = min(min_rotate, count[i].second - same[i]);
                } else {
                    min_rotate = min(min_rotate, count[i].first - same[i]);
                }
            }
        }
        return min_rotate;
    }
};
