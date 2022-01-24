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
        int p_num = 1;
        int s_num = 1;
        vector<int> new_p;
        vector<int> new_s;
        string temp = "";
        
        for (auto& c: pattern) {
            if (!unique_p.count(c)) {
                unique_p[c] = p_num;
                new_p.emplace_back(p_num);
                p_num += 1;
            } else {
                new_p.emplace_back(unique_p[c]);
            }
        }
        
        for (auto& c: s) {
            if (c == ' ') {
                if (!unique_s.count(temp)) {
                    unique_s[temp] = s_num;
                    new_s.emplace_back(s_num);
                    s_num += 1;
                } else {
                    new_s.emplace_back(unique_s[temp]);
                }
                temp = "";
            } else {
                temp += c;
            }
        }
        
        if (!unique_s.count(temp)) {
            unique_s[temp] = s_num;
            new_s.emplace_back(s_num);
            s_num += 1;
        } else {
            new_s.emplace_back(unique_s[temp]);
        }
        
//         cout << "pattern: ";
//         for (auto& v: new_p) {
//             cout << v << " ";
//         }
//         cout << "\n";
        
//         cout << "string: ";
//         for (auto& v: new_s) {
//             cout << v << " ";
//         }
//         cout << "\n";
        
        if (new_s.size() != new_p.size())
            return false;
        
        int n = new_s.size();
        for (int i = 0; i < n; i++) {
            if (new_s[i] != new_p[i])
                return false;
        }
        return true;
    }
};
