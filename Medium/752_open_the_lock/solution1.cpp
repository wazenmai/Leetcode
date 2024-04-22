/**
 * Title:  Open the Lock (Leetcode Medium 752)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, April, 2024
 * Method: All transform to int. Use unordered_set to check deadends. Use queue to BFS.
 * Result: Time complexity is O(10000), space complexity is O(10000).
 */

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<int> us;
        for (auto end: deadends) {
            us.insert(stoi(end));
        }
        if (us.find(0) != us.end()) return -1;
        
        int tg = stoi(target);
        if (tg == 0) return 0;

        queue<pair<int, int>> q; // num, step
        vector<bool> visit(10000, false);
        q.push(make_pair(0, 0));
        visit[0] = true;
        while (!q.empty()) {
            auto node = q.front();
            int cur = node.first;
            int step = node.second;
            // cout << "---" << step << " " << cur << "---\n";
            q.pop();
            // 1st, +1000
            int num = (cur >= 9000) ? cur - 9000 : cur + 1000;
            if (!visit[num] && us.find(num) == us.end()) {
                if (num == tg) return step + 1;
                q.push(make_pair(num, step + 1));
                visit[num] = true;
            }
            // 2nd, -1000
            num = (cur < 1000) ? cur + 9000 : cur - 1000;
            if (!visit[num] && us.find(num) == us.end()) {
                if (num == tg) return step + 1;
                q.push(make_pair(num, step + 1));
                visit[num] = true;
            }
            // 3rd, + 100
            num = ((cur / 100) % 10 == 9) ? cur - 900 : cur + 100;
            if (!visit[num] && us.find(num) == us.end()) {
                if (num == tg) return step + 1;
                q.push(make_pair(num, step + 1));
                visit[num] = true;
            }
            // 4th, -100
            num = ((cur / 100) % 10 == 0) ? cur + 900 : cur - 100;
            if (!visit[num] && us.find(num) == us.end()) {
                if (num == tg) return step + 1;
                q.push(make_pair(num, step + 1));
                visit[num] = true;
            }
            // 5th, +10
            num = ((cur / 10) % 10 == 9) ? cur - 90 : cur + 10;
            if (!visit[num] && us.find(num) == us.end()) {
                if (num == tg) return step + 1;
                q.push(make_pair(num, step + 1));
                visit[num] = true;
            }
            // 6th, -10
            num = ((cur / 10) % 10 == 0) ? cur + 90 : cur - 10;
            if (!visit[num] && us.find(num) == us.end()) {
                if (num == tg) return step + 1;
                q.push(make_pair(num, step + 1));
                visit[num] = true;
            }
            // 7th, +1
            num = (cur % 10 == 9) ? cur - 9 : cur + 1;
            if (!visit[num] && us.find(num) == us.end()) {
                if (num == tg) return step + 1;
                q.push(make_pair(num, step + 1));
                visit[num] = true;
            }
            // 8th, -1
            num = (cur % 10 == 0) ? cur + 9 : cur - 1;
            if (!visit[num] && us.find(num) == us.end()) {
                if (num == tg) return step + 1;
                q.push(make_pair(num, step + 1));
                visit[num] = true;
            }
        }
        return -1;
    }
};
