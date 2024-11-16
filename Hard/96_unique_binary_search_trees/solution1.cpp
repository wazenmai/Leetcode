/**
 * Title:  Unique Binary Search Trees (Leetcode Medium 96)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, November, 2024
 * Method: G(n) = # of unique BST for n nodes. F(i, n) = # of unique BST for n nodes with root i. 
 *         G(n) = F(1, n) + F(2, n) + ... + F(n, n). G(0) = 1 (empty), G(1) = 1. F(1, n) = G(n - 1). F(2, n) = G(1) * G(n - 2). F(3, n) = G(2) * G(n - 3).
 * Result: Time complexity O(n^2). Space complexity O(n).
 */

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};

// 1: 1
// 2: 12, 21 2
// 3: 123, 213, 321, 312 5

// G(n): # of unique BST for n nodes
// F(i, n): # of unique BST for n nodes with root i
// G(n) = F(1, n) + F(2, n) + ... + F(n, n)
// G(0) = 1 (empty), G(1) = 1
// F(1, n) = G(n - 1)
// F(2, n) = G(1) * G(n - 2)
// F(3, n) = G(2) * G(n - 3)
// G(2) = 

// G(4) = F(1, n) + F(2, n) + F(3, n) + F(4, n)
//      = G(0) * G(3) + G(1) * G(2) + G(2) * G(1) + G(3) * G(0)


/*
switch(n) {
    case 1: return 1;
    case 2: return 2;
    case 3: return 5; 2 + 1 + 2
    case 4: return 14; 5 + 2 + 2 + 5
    case 5: return 42; 14 + 5 + 4 + 5 + 14
    case 6: return 132;
    case 7: return 429;
    case 8: return 1430;
    case 9: return 4862;
    case 10: return 16796;
    case 11: return 58786;
    case 12: return 208012;
    case 13: return 742900;
    case 14: return 2674440;
    case 15: return 9694845;
    case 16: return 35357670;
    case 17: return 129644790;
    case 18: return 477638700;
    case 19: return 1767263190;
    default: return 0;
}
*/
