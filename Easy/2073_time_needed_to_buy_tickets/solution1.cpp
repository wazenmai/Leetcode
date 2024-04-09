/**
 * Title:  Time Needed To Buy Tickets (Leetcode Easy 2073)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, April, 2024
 * Result: Time complexity is O(nm), space complexity is O(1). n = tickerts.size(), m = tickets[k].
 */

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ticket = tickets[k];
        int time = 0;
        int n = tickets.size();
        for (int i = 1; i < ticket; i++) {
            for (int j = 0; j < n; j++) {
                if (tickets[j] > 0) {
                    tickets[j]--;
                    time++;
                }
            }
        }
        for (int j = 0; j <= k; j++) {
            if (tickets[j] > 0) {
                tickets[j]--;
                time++;
            }
        }
        return time;
    }
};
