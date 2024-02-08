/**
 * Title:  Perfect Squares (Leetcode Medium 279)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   08, February, 2024
 * Method: BFS. Start from n, and push n - i * i into queue. If n - i * i == 0, return ans. If not, ans++. By this we can find the answer as soon as possible.
 * Result: Time complexity O(n * sqrt(n)), Space complexity O(n).
 */

class Solution {
public:
    int numSquares(int n) {
        // BFS
        queue<int> q;

        int s_num = 100;
        while (n < s_num * s_num) --s_num;

        q.push(n);
        int ans = 1;
        while (!q.empty()) {
            int size = q.size();
            // choose next number
            while (size--) {
                int cur = q.front();
                q.pop();
                for (int i = s_num; i >= 0; i--) {
                    if (cur - i * i < 0) continue;
                    if (cur - i * i == 0) return ans;
                    q.push(cur - i * i);
                }
            }
            ans++;
        }
        return ans;
    }
};
