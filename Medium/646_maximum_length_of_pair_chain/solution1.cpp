/**
 * Title:  Maximum Length of Pair Chain (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   26, August, 2023
 * Method: Greedy with sorting by the second element. Time complexity O(nlogn), space complexity O(1)
 */

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    void printPairs(vector<vector<int>>& pairs) {
        for (auto p: pairs) {
            cout << "(" << p[0] << "," << p[1] << ") ";
        }
        cout << "\n";
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        printPairs(pairs);
        int n = pairs.size();
        int ans = 1;
        int last = pairs[0][1];
        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > last) {
                ans++;
                last = pairs[i][1];
            }
        }
        return ans;
    }
};
