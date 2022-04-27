/**
 * Title:  Smallest String with Swaps (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, April, 2022
 * Result: TLE.
 */

class Solution {
private:
    unordered_map<string, int> h;
    string ans;
    int n;
public:
    void compare (string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] < ans[i]) {
                ans = s;
                break;
            } else if (s[i] > ans[i]) {
                break;
            }
        }
    }
    
    void dfs(string s, vector<vector<int>>& pairs, int id) {
        // compare to ans
        compare(s);
        h[s] = 1;
         
        // dfs others
        for (int i = 0; i < n; i++) {
            if (i == id)
                continue;
            string ns = s;
            char temp = ns[pairs[i][0]];
            ns[pairs[i][0]] = ns[pairs[i][1]];
            ns[pairs[i][1]] = temp;
            cout << "from " << s << " to " << ns << ": " << h[ns] << "\n";
            if (!h[ns])
                dfs(ns, pairs, i);
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        n = (int)pairs.size();
        if (n == 0)
            return s;
        
        ans = s;
        h[s] = 1;
        
        // dfs
        for (int i = 0; i < n; i++) {
            // first swap
            string ns = s;
            char temp = ns[pairs[i][0]];
            ns[pairs[i][0]] = ns[pairs[i][1]];
            ns[pairs[i][1]] = temp;
            cout << "from " << s << " to " << ns << ": " << h[ns] << "\n";
            if (!h[ns]) {
                dfs(ns, pairs, i);
            }
        }
        return ans;
    }
};
