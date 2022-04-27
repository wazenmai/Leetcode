/**
 * Title:  Smallest String with Swaps (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, April, 2022
 * Method: Use disjoint set to group indices together, use min heap sort the characters belonging to same group, then construct new string.
 */

class Union {
// I am a union-find set.
private:
    int *p;
public:
    Union(int n) {
        p = new int[n];
        for (int i = 0; i < n; i++)
            p[i] = i;
    }
    
    int find(int x) {
        if (p[x] == x)
            return x;
        return (p[x] = find(p[x]));
    }
    
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        p[x] = y;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int l = s.length();
        
        Union u = Union(l);
        for (auto& p : pairs) {
            u.merge(p[0], p[1]);
        }
        
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> cg;
        for (int i = 0; i < l; i++) {
            cg[u.find(i)].push(s[i]);
        }
        
        string ans;
        ans.reserve(l);
        
        for (int i = 0; i < l; i++) {
            priority_queue<char, vector<char>, greater<char>>& pq = cg[u.find(i)];
            ans.append(&pq.top(), 1);
            pq.pop();
        }
        return ans;
    }
};
