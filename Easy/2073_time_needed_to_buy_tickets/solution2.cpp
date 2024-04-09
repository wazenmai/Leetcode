/**
 * Title:  Time Needed To Buy Tickets (Leetcode Easy 2073)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, April, 2024
 * Result: Time complexity is O(n), space complexity is O(1). n = tickerts.size().
 */

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int target = tickets[k];
        int time = target;
        int n = tickets.size();
        // People in front of k
        for (int i = 0; i < k; i++) {
            time += min(target, tickets[i]);
        }
        target--;
        // People behind k
        for (int i = k + 1; i < n; i++) {
            time += min(target, tickets[i]);
        }
        return time;
    }
};
