/**
 * Title:  Lexicographically Smallest Equivalent String (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, Janurary, 2023
 * Result: Speed 100%, Memory 29.36%
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
        if (x < y)
            p[y] = x;
        else
            p[x] = y;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        Union u = Union(26);
        int n = s1.length();
        for (int i = 0; i < n; i++) {
            u.merge(s1[i] - 'a', s2[i] - 'a');
        }
        // for (int i = 0; i < 26; i++) {
        //     cout << char('a' + i) << ": " << char(u.find(i) + 'a') << "\n";
        // }
        n = baseStr.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += (u.find(baseStr[i] - 'a') + 'a');
        }
        return ans;
    }
};