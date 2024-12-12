/**
 * Title:  Take Gifts From the Richest Pile (Leetcode Easy 2558)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, December, 2024
 * Result: Time complexity is O(nlogn + klogn), space complexity is O(n). n is the number of gifts.
 */

class Solution {
public:
    long long pickGifts(const vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for (auto& gift: gifts) {
            ans += gift;
            pq.push(gift);
        }
        for (int i = 0; i < k; i++) {
            if (pq.empty()) return 0;
            int rich = pq.top();
            pq.pop();
            int new_rich = sqrt(rich);
            ans -= (rich - new_rich);
            pq.push(new_rich);
        }
        return ans;
    }
};
