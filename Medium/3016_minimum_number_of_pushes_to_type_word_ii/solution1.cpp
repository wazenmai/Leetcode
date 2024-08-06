/**
 * Title:  Minimum Number of Pushes to Type Word II (Leetcode Medium 3016)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, August, 2024
 * Result: Time complexity O(n), Space complexity O(1). // because sorting cnt is O(1).
 */

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26, 0);
        for (auto& c: word) {
            cnt[c - 'a']++;
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        int push = 0;
        for (int i = 0; i < 26; i++) {
            push += (i / 8 + 1) * cnt[i];
        }
        return push;
    }
};
