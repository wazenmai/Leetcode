/**
 * Title:  Maximum Length of a Concatenated String with Unique Characters (Leetcode Medium 1239)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, Janurary, 2024
 * Method: Use DFS to find all possible combination, and check if the combination is unique.
 * Result: Time complexity O(2^N). Space complexity O(N)
 */

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans = 0;
        dfs(arr, "", 0, ans);
        return ans;
    }

    void dfs(const vector<string>& arr, const string& path, int idx, int& res) {
        if (isUnique(path)) res = max(res, (int)path.length());
        if (idx == arr.size() || !isUnique(path)) return;
        for (int i = idx; i < arr.size(); i++) {
            dfs(arr, path + arr[i], i + 1, res);
        }
    }

    bool isUnique(const string& s) {
        int dup = 0;
        int a = 0;
        for (char c: s) {
            dup |= (a & (1 << (c - 'a')));
            a |= 1 << (c - 'a');
        }
        if (dup > 0) return false;
        return true;
    }
};

// N = arr.size(), M = max length of s
// Time complexity O(2^N), dfs explore all possible combination
// Space complexity O(N). space is used for the recursive call stack.
