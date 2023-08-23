/**
 * Title:    Reorganize String (Leetcode Medium)
 * Author:   Bronwin Chen <iotbwu0101@gmail.com>
 * Date:     23, August, 2023
 * Method:   Use priority queue to store the frequency of each character, every time we take two chars with biggset frequecy and append.
 * Analysis: Time complexity O(n * klogk), space complexity O(n), k is the number of unique characters
 */

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }

        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                char c = 'a' + i;
                pq.push(make_pair(count[i], 'a' + i));
            }
        }

        string ans = "";
        while (!pq.empty()) {
            auto f = pq.top();
            // cout << "take f: " << f.first << ", " << f.second << "\n";
            pq.pop();
            if (pq.empty()) {
                ans += f.second;
                break;
            }
            auto s = pq.top();
            // cout << "take s: " << s.first << ", " << s.second << "\n";
            pq.pop();
            ans += f.second;
            ans += s.second;
            // cout << "ans: " << ans << "\n";
            if (f.first != 1)
                pq.push(make_pair(f.first - 1, f.second));
            if (s.first != 1)
                pq.push(make_pair(s.first - 1, s.second));
        }
        // cout << "ans: " << ans << " " << ans.length();
        if (ans.length() == n)
            return ans;
        return "";
    }
};
