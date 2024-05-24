/**
 * Title:  Maximum Score Words Formed by Letters (Leetcode Hard 1255)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, May, 2024
 * Method: Use a vector to store the frequency of each letter. For each word, we can either take it or not.
    * If take, we need to check if we have enough letters and recover the `cnt` after recursion.
 * Result: Time complexity is O(2^n). Space complexity is O(26)=O(1).
 */


class Solution {
private:
    int ans;
public:
    void findSubset(vector<string>& words, vector<int>& score, vector<int>& cnt, int id, int res) {
        if (id == words.size()) { // reach the end
            ans = max(ans, res);
            return;
        }
        
        // take
        bool flag = true;
        int org_res = res;
        int i;
        for (i = 0; i < words[id].length(); i++) {
            if (cnt[words[id][i] - 'a'] == 0) {
                flag = false;
                break;
            } else {
                cnt[words[id][i] - 'a']--;
                res += score[words[id][i] - 'a'];
            }
        }
        if (!flag) {
            for (int j = 0; j < i; j++) {
                cnt[words[id][j] - 'a']++;
            }
        } else {
            findSubset(words, score, cnt, id + 1, res);
            for (int j = 0; j < words[id].length(); j++) {
                cnt[words[id][j] - 'a']++;
            }
        }
        res = org_res;
        // not take
        findSubset(words, score, cnt, id + 1, res);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> cnt(26);
        for (char& c: letters) {
            cnt[c - 'a']++;
        }
        // Find all subset of words that satisfy cnt
        ans = 0;
        findSubset(words, score, cnt, 0, 0);
        return ans;
    }
};
