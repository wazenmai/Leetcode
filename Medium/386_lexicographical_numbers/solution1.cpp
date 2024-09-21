/**
 * Title:  Lexicographical Numbers (Leetcode Medium 386)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   21, September, 2024
 * Method: View it as a tree, do dfs.
 * Result: Time complexity O(n), Space complexity O(d) = O(1), where d is the number of digits of n, since n is at most 50000, O(5) = O(1).
 */

class Solution {
private:
    vector<int> ans;
public:
    void dfs(int num, int n) {
        if (num > n) return;
        ans.emplace_back(num);
        for (int i = 0; i <= 9; i++) {
            dfs(num * 10 + i, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i <= 9; i++) {
            if (i <= n)
                dfs(i, n);
        }
        return ans;
    }
};

// n = 1000
// 1,10,100,1000,1001,1002,101,102,11,110