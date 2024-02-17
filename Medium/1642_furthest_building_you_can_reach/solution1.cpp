/**
 * Title:  Furthest Building You Can Reach (Leetcode Medium 1642)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, February, 2024
 * Method: Ladders-first approach. Use min heap to store the jumps that ladders did, when run out of ladders, check min heap and use bricks to replace the smallest jump.
 * Result: Time complexity O(nlogn), space complexity O(n). Runtime 79 ms, Memory 57.3 MB.
 */

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        // ladders-first approach
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i < n; i++) {
            if (heights[i] - heights[i - 1] <= 0) continue;
            int diff = heights[i] - heights[i - 1];
            if (ladders > 0) {
                ladders--;
                q.push(diff);
            } else if (!q.empty() && bricks >= q.top() && q.top() < diff) {
                bricks -= q.top();
                q.pop();
                q.push(diff);
            } else if (bricks >= diff) {
                bricks -= diff;
            } else {
                return i - 1;
            }
        }
        return n - 1;
    }
};
