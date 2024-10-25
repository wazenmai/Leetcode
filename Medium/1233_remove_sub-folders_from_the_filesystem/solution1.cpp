/**
 * Title:  Remove Sub-Folders from the Filesystem (Leetcode Medium 1233)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   25, October, 2024
 * Method: Sort the folders by length, this can make sure we check parent folder first. Then use unordered_set to store unseen folders.
 * Result: Time complexity is O(nlogn), space complexity is O(n).
 */

class Solution {
public:
    static bool cmp(string& a, string& b) {
        return a.length() < b.length();
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), cmp);
        unordered_set<string> us;
        for (auto& s: folder) {
            string fold = "/";
            int i = 1;
            bool subfolder = false;
            while (i < s.length()) {
                if (s[i] == '/') {
                    if (us.find(fold) != us.end()) {
                        subfolder = true;
                        break;
                    } else {
                        fold += s[i];
                    }
                } else {
                    fold += s[i];
                }
                i++;
            }
            if (!subfolder) {
                us.insert(s);
            }
        }
        vector<string> ans;
        for (auto it = us.begin(); it != us.end(); it++) {
            ans.emplace_back(*it);
        }
        return ans;
    }
};
