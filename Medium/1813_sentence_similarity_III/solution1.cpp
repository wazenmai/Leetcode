/**
 * Title:  Sentence Similarity III (Leetcode Medium 1813)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, October, 2024
 * Method: Add space behind s1 and s2 for prettier code. Let s1 be the short sentence. We find the point from left to right that s1 and s2 are different, if i reaches s1 end and all same now, return true.
 *         If not, we iterate through s2 to find the point that n - i == m - j, and check if the rest of s1 and s2 are the same.
 * Result: Time complexity is O(n + m), Space complexity is O(1).
 */

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        sentence1 += " ";
        sentence2 += " ";
        int n = sentence1.length(), m = sentence2.length();
        if (n > m) {
            string temp = sentence1;
            sentence1 = sentence2;
            sentence2 = temp;
            n = sentence1.length();
            m = sentence2.length();
        }
        // cout << sentence1 << ".\n" << sentence2 << ".\n";
        int i = 0, j = 0;
        string word1 = "", word2 = "";
        while (i < n && j < m) {
            if (sentence1[i] == ' ' && sentence2[j] == ' ') {
                if (word1 == word2) {
                    word1 = word2 = "";
                    i++;
                    j++;
                    continue;
                } else {
                    break; // i, j at space
                }
            } else if (sentence1[i] == ' ') {
                while (j < m && sentence2[j] != ' ') {
                    word2 += sentence2[j++];
                }
                break;
            } else if (sentence2[j] == ' ') {
                while (i < n && sentence1[i] != ' ') {
                    word1 += sentence1[i++];
                }
                break;
            }
            word1 += sentence1[i++];
            word2 += sentence2[j++];
        }
        if (i == n && word1 == word2) return true; // reach s1 end and all same now
        // cout << "s1: (" << i << "," << sentence1[i] << "), word1=" << word1 << "\n";
        // cout << "s2: (" << j << "," << sentence2[j] << "), word2=" << word2 << "\n";
        if (sentence2[j] == ' ') { // jump space
            j++;
            word2 = "";
        }
        while (j < m) {
            if (sentence2[j] == ' ') {
                // cout << word2 << "\n";
                if (n - i == m - j) {
                    if (word1 != word2) return false;
                    if (sentence1.substr(i) != sentence2.substr(j)) return false;
                    return true;
                }
                word2 = "";
                j++;
                continue;
            }
            word2 += sentence2[j++];
        }
        return false;
    }
};
