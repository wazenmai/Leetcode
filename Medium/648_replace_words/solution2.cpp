/**
 * Title:  Replace Words (Leetcode Medium 648)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, June, 2024
 * Method: Use unordered_set to store dictionary, then iterate through sentence to find the shortest prefix match.
 * Result: Time complexity is O(nw + mw), where n is the size of dictionary, m = # of words in sentence, w = average length of each word. Space complexity is O(n).
 */

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans = "";
        unordered_set<string> s;
        for (auto& root: dictionary) {
            s.insert(root);
        }
        sentence += " ";
        
        string temp = "";
        for (auto& c: sentence) {
            if (c == ' ') {
                int n = temp.length();
                string root = "";
                for (int i = 0; i < n; i++) {
                    root += temp[i];
                    if (s.find(root) != s.end()) {
                        break;
                    }
                }
                ans += root;
                ans += " ";
                temp = "";
            } else {
                temp += c;
            }
        }
        ans.pop_back();
        return ans;
    }
};
