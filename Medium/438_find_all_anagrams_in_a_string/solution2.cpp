/**
 * Title:  Find All Anagrams in a String (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   2, Feb, 2022
 * Method: Hash table to 26 letters
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> p_hash(26, 0);
        vector<int> s_hash(26, 0);
        int n = s.length();
        int m = p.length();
        
        if (m > n)
            return ans;
        
        // first check
        for (int i = 0; i < m; i++) {
            p_hash[p[i] - 'a']++;
            s_hash[s[i] - 'a']++;
        }
        
        if (p_hash == s_hash)
            ans.emplace_back(0);
        
        for (int i = m; i < n; i++) {
            s_hash[s[i - m] - 'a']--;
            s_hash[s[i] - 'a']++;
            if (p_hash == s_hash)
                ans.emplace_back(i - m + 1);
        }
        return ans;
    }
};
