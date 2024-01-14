/**
 * Title:  Determine if Two Strings Are Close (Leetcode Medium 1657)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, Janurary, 2024
 * Method: You can only swap two existing characters and swap the frequency of existing characters.
    *         So, the length of strings must be same. The alphabet of strings must be same.
    *         Last but not least, the frequency of each alphabet must be same.
 * Result: Time complexity O(n + 26 + 26log26 + 26) = O(n). Space complexity O(26 + 26 + 26 + 26) = O(1).
 */

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if (n != m) return false;
        vector<int> cnt1(26, 0);
        vector<int> cnt2(26, 0);
        for (int i = 0; i < n; i++) {
            cnt1[word1[i] - 'a']++;
            cnt2[word2[i] - 'a']++;
        }
        vector<int> w1;
        vector<int> w2;
        for (int i = 0; i < 26; i++) {
            if (cnt1[i] == 0 && cnt2[i] > 0) return false;
            if (cnt1[i] > 0 && cnt2[i] == 0) return false;
            if (cnt1[i] > 0) w1.emplace_back(cnt1[i]);
            if (cnt2[i] > 0) w2.emplace_back(cnt2[i]);
        }
        sort(w1.begin(), w1.end());
        sort(w2.begin(), w2.end());
        n = w1.size();
        for (int i = 0; i < n; i++) {
            if (w1[i] != w2[i]) return false;
        }
        return true;
    }
};
// aaabbbbccddeeeeefffff

// aaaaabbcccdddeeeeffff
// cccaabbaaadddeeeeffff
// cccaaaabbadddeeeeffff
// 
