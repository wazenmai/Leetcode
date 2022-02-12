/**
 * Title:  Permutation in String (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, Feb, 2022
 */

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_hash(26, 0);
        vector<int> s2_hash(26, 0);
        int n = s2.length();
        int m = s1.length();
        if (m > n)
            return false;
        for (int i = 0; i < m; i++) {
            s1_hash[s1[i] - 'a']++;
            s2_hash[s2[i] - 'a']++;
        }
        if (s1_hash == s2_hash)
            return true;
        for (int i = m; i < n; i++) {
            s2_hash[s2[i - m] - 'a']--;
            s2_hash[s2[i] - 'a']++;
            if (s1_hash == s2_hash)
                return true;
        }
        return false;
    }
};
