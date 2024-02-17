/**
 * Title:  Furthest Building You Can Reach (Leetcode Medium 1642)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, February, 2024
 * Method: Bricks-first approach. Use max heap to store the jumps that bricks did, when run out of bricks, check max heap and use ladders to replace the largest jump.
 * Result: Time complexity O(nlogn), space complexity O(n). Runtime 64 ms, Memory 57.52 MB.
 */

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // bricks-first approach
        int n = heights.size();
        priority_queue<int> q;
        for (int i = 1; i < n; i++) {
            if (heights[i] - heights[i - 1] <= 0) continue;
            int diff = heights[i] - heights[i - 1];
            if (bricks >= diff) {
                q.push(diff);
                bricks -= diff;
            } else if (ladders > 0) {
                ladders--;
                if (!q.empty() && q.top() > diff) {
                    bricks += (q.top() - diff);
                    q.pop();
                    q.push(diff);
                }
            } else {
                return i - 1;
            }
        }
        return n - 1;
    }
};
