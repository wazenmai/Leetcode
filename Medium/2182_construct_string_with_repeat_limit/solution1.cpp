/**
 * Title:  Construct String With Repeat Limit (Leetcode Medium 2182)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, December, 2024
 * Method: Use max-heap to find the next added char.
 * Result: Time complexity O(n * log(26)), Space complexity O(26).
 */

class Solution {
public:
    string repeatLimitedString(const string s, const int repeatLimit) {
        vector<int> cnt(26, 0);
        for (auto& c: s) {
            cnt[c - 'a']++;
        }
        string ans = "";
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                pq.push(make_pair(i, cnt[i]));
            }
        }
        while (!pq.empty()) {
            auto [id, num] = pq.top();
            char c = 'a' + id;
            // cout << c << ": " << num << "\n";
            pq.pop();
            if (num > repeatLimit) {
                for (int i = 0; i < repeatLimit; i++)
                    ans += c;
                if (!pq.empty()) {
                    auto [id2, num2] = pq.top();
                    pq.pop();
                    char c2 = 'a' + id2;
                    ans += c2;
                    // cout << "c2: " << c2 << ": " << num2 << "\n";
                    if (num2 > 1) {
                        pq.push(make_pair(id2, num2 - 1));
                    }
                } else {
                    break;
                }
                pq.push(make_pair(id, num - repeatLimit));
            } else {
                for (int i = 0; i < num; i++)
                    ans += c;
            }
        }
        return ans;
    }
};
