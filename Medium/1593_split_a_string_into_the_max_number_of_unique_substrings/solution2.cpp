/**
 * Title:  Split a String Into the Max Number of Unique Substrings (Leetcode Medium 1593)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, October, 2024
 * Method: Add pruning technique. When the number of unique strings will not be bigger than current answer, return.
 * Result: Time complexity is O(2^n), space complexity is O(n). Runtime: 207ms -> 15ms. Memory: 47.7MB -> 12.7MB.
 */

class Solution {
private:
    int ans;
    int n;
public:
    void backtrack(string& s, int i, unordered_set<string>& us) {
        if (i == n) {
            ans = max(ans, (int)us.size());
            return;
        }
        if (us.size() + (n - i) <= ans) return;
        string temp = "";
        for (int len = 1; len <= n - i; len++) {
            temp += s[i + len - 1];
            if (us.find(temp) == us.end()) {
                us.insert(temp);
                backtrack(s, i + len, us);
                us.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string& s) {
        unordered_set<string> us;
        n = s.length();
        ans = 1;
        backtrack(s, 0, us);
        return ans;
    }
};
