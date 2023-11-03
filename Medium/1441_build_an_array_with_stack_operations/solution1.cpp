/**
 * Title:  Build an Array With Stack Operations (Leetcode Medium 1441)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   03, November, 2023
 */

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i = 0;
        int t = target.size();
        for (int num = 1; num <= n; num++) {
            ans.emplace_back("Push");
            if (num != target[i]) {
                ans.emplace_back("Pop");
            } else {
                i++;
            }
            if (i == t)
                break;
        }
        return ans;
    }
};
