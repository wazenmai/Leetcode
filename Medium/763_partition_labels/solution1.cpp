/**
 * Title:  Partition Labels (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, Mar, 2022
 */

class Solution {
private:
    void print_vec(vector<pair<char, pair<int, int>>>& v) {
        cout << "[";
        char c = 'a';
        for (auto& x : v) {
            cout << c << ": (" << x.second.first << ", " << x.second.second << ")\n";
            c++;
        }
    }
    
    void print_vec2(vector<int>& v) {
        cout << "[";
        for (auto& x : v) {
            cout << x << " ";
        }
        cout <<  "]\n";
    }
public:
    static bool compare(pair<char, pair<int, int>>& a, pair<char, pair<int, int>>& b) {
        return a.second.first < b.second.first;
    }
    vector<int> partitionLabels(string s) {
        vector<pair<char, pair<int, int>>> v;
        for (int i = 0; i < 26; i++) {
            v.emplace_back(make_pair('a' + i, make_pair(1000, 1000)));
        }
        vector<int> count(26, 0);
        vector<int> ans;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (v[s[i] - 'a'].second.first == 1000) {
                v[s[i] - 'a'].second.first = i;
                v[s[i] - 'a'].second.second = i;
            } else {
                v[s[i] - 'a'].second.second = i;
            }
            count[s[i] - 'a']++;
        }
        sort(v.begin(), v.end(), compare);
        // print_vec2(count);
        // print_vec(v);
        int partition = 0;
        int end = 0;
        for (int i = 0; i < 25; i++) {
            end = max(end, v[i].second.second);
            if (v[i].second.first == 1000)
                break;
            if (end > v[i + 1].second.first) {
                partition += count[v[i].first - 'a'];
            } else {
                partition += count[v[i].first - 'a'];
                ans.emplace_back(partition);
                partition = 0;
            }
        }
        if (v[25].second.first != 1000)
            ans.emplace_back(partition + count[v[25].first - 'a']);
        
        return ans;
    }
};
