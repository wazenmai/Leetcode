/**
 * Title:  Baseball Game (Leetcode Easy)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, April, 2022
 */

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> score;
        int n = 0;
        for (auto& op : ops) {
            if (op == "+") {
                score.emplace_back(score[n - 1] + score[n - 2]);
                n++;
            } else if (op == "D") {
                score.emplace_back(score[n - 1] * 2);
                n++;
            } else if (op == "C") {
                score.pop_back();
                n--;
            } else {
                score.emplace_back(stoi(op));
                n++;
            }
        }
        n = 0;
        for (auto& x : score)
            n += x;
        return n;
    }
};
