/**
 * Title:  Construct String With Repeat Limit (Leetcode Medium 2182)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, December, 2024
 * Method: Use loop to find next char instead of heap.
 * Result: Time complexity O(n * 26), Space complexity O(26).
 */

class Solution {
public:
    string repeatLimitedString(const string s, const int repeatLimit) {
        vector<int> cnt(26, 0);
        for (auto& c: s) {
            cnt[c - 'a']++;
        }
        string ans = "";
        int cur = 25;
        while (cur >= 0) {
            if (cnt[cur] == 0) {
                cur--;
                continue;
            }
            char c = 'a' + cur;
            if (cnt[cur] > repeatLimit) {
                for (int i = 0; i < repeatLimit; i++) {
                    ans += c;
                }
                cnt[cur] -= repeatLimit;
                // find next char
                int nxt = cur - 1;
                while (nxt >= 0 && cnt[nxt] == 0) {
                    nxt--;
                }
                if (nxt < 0) break;
                char c2 = 'a' + nxt;
                ans += c2;
                cnt[nxt]--;
            } else {
                for (int i = 0; i < cnt[cur]; i++) {
                    ans += c;
                }
                cnt[cur] = 0;
            }
        }
        return ans;
    }
};
