/**
 * Title:  Minimum Deletions to Make Character Frequencies Unique (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, September, 2023
 * Method: O(N)
 */

class Solution {
public:
    void printVec(vector<int>& v) {
        for (int i = 0; i < 26; i++) {
            if (v[i] == 0)
                continue;
            char c = 'a' + i;
            cout << c << ": " << v[i] << "\n";
        }
    }
    void printMap(unordered_map<int, vector<int>>& m) {
        for (auto it = m.begin(); it != m.end(); it++) {
            cout << it->first << ": ";
            for (auto e : it->second) {
                char c = 'a' + e;
                cout << c << " ";
            }
            cout << "\n";
        }
    }
    int minDeletions(string s) {
        // Step 1. Count occurence
        vector<int> count(26, 0);
        for (auto& c: s) {
            count[c - 'a']++;
        }
        // Step 2. Know each occurence has how many characters
        unordered_map<int, int> m;
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                if (m.find(count[i]) != m.end()) {
                    m[count[i]]++;
                } else {
                    m[count[i]] = 1;
                }
            }
        }
        // Step 3. Delete the characters to 0 or occurence haven't appear.
        int ans = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            // cout << it->first << ": " << it->second << "\n";
            while (it->second > 1) {
                int d = 1; // # characters to delete
                for (int i = it->first - 1; i > 0; i--) {
                    if (m.find(i) == m.end()) {
                        m[i] = 1;
                        break;
                    }
                    d++;
                }
                ans += d;
                --it->second;
            }
        }
        return ans;
    }
};
