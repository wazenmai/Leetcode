/**
 * Title:  Find the Winner of an Array Game (Leetcode Medium 1535)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   05, November, 2023
 */

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
        
        int n = arr.size();
        int ans = 0;
        if (k >= n - 1) { // find max
            ans = 0;
            for (int& num: arr) {
                ans = max(num, ans);
            }
            return ans;
        }
        int i = 0; // win
        int j = 1; // contestant
        int win = 0; // win_count
        while (win < k) {
            // cout << i << ", " << j << ", " << win << "\n";
            if (arr[i] > arr[j]) {
                j = (j == n - 1) ? 1 : j + 1;
                win++;
            } else {
                i = j;
                win = 1;
                j = (j == n - 1) ? 1 : j + 1;
            }
        }
        return arr[i];
    }
};