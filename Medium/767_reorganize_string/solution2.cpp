/**
 * Title:    Reorganize String (Leetcode Medium)
 * Author:   Bronwin Chen <iotbwu0101@gmail.com>
 * Date:     23, August, 2023
 * Method:   Sort characters by frequency, then append them to the string's odd positions then even, so as to avoid the same characters adjacent.
 * Analysis: Time complexity O(n + klogk), space complexity O(n), k is the number of unique characters
 */

class Solution {
public:
    static bool compare(pair<int, char>& a, pair<int, char>& b) {
        return a.first > b.first;
    }
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }

        vector<pair<int, char>> v;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0)
                v.push_back({count[i], 'a' + i});
        }
        sort(v.begin(), v.end(), compare);
        if (v[0].first > (n + 1) / 2) // adjacent occurence
            return "";
        string ans(n, ' ');
        int i = 0;
        for (auto e: v) {
            for (int j = 0; j < e.first; j++) {
                if (i >= n) {
                    i = 1;
                }
                ans[i] = e.second;
                i += 2;
            }
        }
        return ans;
    }
};

/*
Time complexity for priority queue approach
- O(n): count freq
- O(klogk): build max heap
- Heap insertion and deletion: O(nlogk) = O(n * log26) = O(n)

Time complexity for array sorting: O(n + klogk)
*/

