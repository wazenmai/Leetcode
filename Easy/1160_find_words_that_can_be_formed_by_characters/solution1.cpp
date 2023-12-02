/**
 * Title:  Find Words That Can Be Formed By Characters (Leetcode Easy 1160)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   02, December, 2023
 * Result: Time complexity: O(26n) = O(n), Space complexity: O(1).
 */

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> v(26, 0);
        for (auto& c: chars) {
            v[c-'a']++;
        }
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> temp = v;
            bool exceed = false;
            for (auto& c: words[i]) {
                temp[c-'a']--;
                if (temp[c-'a'] < 0) {
                    exceed = true;
                    break;
                }
            }
            if (!exceed) {
                ans += words[i].size();
            }
        }
        return ans;
    }
};
