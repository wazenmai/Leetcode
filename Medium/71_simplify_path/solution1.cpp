/**
 * Title:  Simplify Path (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, Mar, 2022
 */

class Solution {
public:
    string simplifyPath(string path) {
        string ans = "/";
        string temp = "";
        path += "/";
        int dot = 0;
        int n = path.length();
        for (int i = 1; i < n; i++) {
            // cout << path[i] << " " << ans << "\n";
            if (path[i] == '/') {
                if (temp == ".." && ans.length() != 1) {
                    if (ans.back() == '/')
                        ans.pop_back();
                    while (ans.back() != '/')
                        ans.pop_back();
                } else if (temp != ".." && temp != ".") {
                    ans += temp; 
                    if (ans.back() != '/')
                        ans += "/";
                }
                temp = "";
            } else {
                temp += path[i];
            }
        }
        if (ans.back() == '/' && ans.length() != 1)
            ans.pop_back();
        return ans;
    }
};
