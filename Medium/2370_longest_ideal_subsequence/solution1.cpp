/**
 * Title:  Longest Ideal Subsequence (Leetcode Medium 2370)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, April, 2024
 * Method: Use priority_queue to record the longest ideal string length.
 * Result: Time complexity is O(nlogn ~ n^2 * logn), space complexity is O(n).
 */

class Compare {
public:
    bool operator()(pair<char, int>& a, pair<char, int>& b) {
        if (a.second < b.second)
            return true;
        return false;
    }
};

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq; // (char, len)
        pq.push(make_pair(s[0], 1));
        for (int i = 1; i < n; i++) {
            queue<pair<char, int>> temp;
            while (!pq.empty()) {
                auto cur = pq.top();
                if (abs(s[i] - cur.first) <= k) {
                    pq.push(make_pair(s[i], cur.second + 1));
                    break;
                }
                temp.push(cur);
                pq.pop();
            }
            if (temp.size() == i) {
                pq.push(make_pair(s[i], 1));
            }
            while (!temp.empty()) {
                pq.push(temp.front());
                temp.pop();
            }
        }
        return pq.top().second;
    }
};

// dp[i]: record the longest ideal string length