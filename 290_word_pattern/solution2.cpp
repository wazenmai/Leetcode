/**
 * Title:  Word Pattern (Leetcode Easy 290)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   17, Jan, 2022
 */

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, int> unique_p;
        map<string, int> unique_s;
        int p_num = 0;
        int s_num = 0;
        string temp = "";
        
        string::iterator it_p = pattern.begin();
        string:: iterator it_s = s.begin();
        while (it_p != pattern.end()) {
            if (it_s == s.end()) {
                if (!unique_s.count(temp)) {
                    unique_s[temp] = s_num;
                    s_num++;
                }
                if (!unique_p.count(*it_p)) {
                    unique_p[*it_p] = p_num;
                    p_num++;
                }
                if (unique_p[*it_p] != unique_s[temp]) {
                    return false;
                }
                it_p++;
                break;
            }
            if (*it_s != ' ') {
                temp += *it_s;
                it_s++;
                continue;
            } else {
                if (!unique_s.count(temp)) {
                    unique_s[temp] = s_num;
                    s_num++;
                }
                if (!unique_p.count(*it_p)) {
                    unique_p[*it_p] = p_num;
                    p_num++;
                }
                if (unique_p[*it_p] != unique_s[temp]) {
                    return false;
                }
                temp = "";
                it_s++;
                it_p++;
            }
        }
        if (it_p != pattern.end() || it_s != s.end())
            return false;
        return true;
    }
};
