/**
 * Title:  Replace Words (Leetcode Medium 648)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, June, 2024
 * Method: Iterate through sentence to get word, then iterate through dictionary to find the shortest prefix match.
 * Result: Time complexity is O(mnw), where n is the size of dictionary, m = # of words in sentence, w = average length of each word. Space complexity is O(1).
 */

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans = "";
        int n = dictionary.size();
        
        string temp = "";
        for (auto& c: sentence) {
            if (c == ' ') {
                // find words in dictionary to match temp
                // cout << "temp: " << temp;
                int id = -1;
                for (int i = 0; i < n; i++) {
                    int m = dictionary[i].length();
                    bool flag = true;
                    for (int j = 0; j < m; j++) {
                        if (dictionary[i][j] != temp[j]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        if (id == -1) {
                            id = i;
                        } else {
                            if (dictionary[id].length() > dictionary[i].length()) {
                                id = i;
                            }
                        }
                    }
                }
                // cout << ", id: " << id << "\n";
                if (id == -1) {
                    ans += temp;
                } else {
                    ans += dictionary[id];
                }
                
                ans += " ";
                temp = "";
            } else {
                temp += c;
            }
        }
        int id = -1;
        for (int i = 0; i < n; i++) {
            int m = dictionary[i].length();
            bool flag = true;
            for (int j = 0; j < m; j++) {
                if (dictionary[i][j] != temp[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (id == -1) {
                    id = i;
                } else {
                    if (dictionary[id].length() > dictionary[i].length()) {
                        id = i;
                    }
                }
            }
        }
        if (id == -1) {
            ans += temp;
        } else {
            ans += dictionary[id];
        }
        return ans;
    }
};
