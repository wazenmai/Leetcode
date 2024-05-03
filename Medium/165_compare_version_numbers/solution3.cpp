/**
 * Title:  Compare Version Numbers (Leetcode Medium 165)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, May, 2024
 * Result: 3ms. (slower but tidy code)
 */

class Solution {
public:
    pair<int, int> get_str(string& s, int id, int len) {
        string temp = "0";
        while (id < len && s[id] != '.') {
            if (temp.length() == 1 && temp[0] == '0') {
                temp[0] = s[id];
            } else {
                temp += s[id];
            }
            id++;
        }
        return make_pair(stoi(temp), id);
    }
    int compareVersion(string version1, string version2) {
        int n = version1.length(), m = version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            auto v1 = get_str(version1, i, n); // num, id
            auto v2 = get_str(version2, j, m);
            
            if (v1.first > v2.first) return 1;
            if (v2.first > v1.first) return -1;
            i = v1.second + 1;
            j = v2.second + 1;
        }
        return 0;
    }
};