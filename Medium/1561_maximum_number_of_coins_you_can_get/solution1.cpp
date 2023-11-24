/**
 * Title:  Maximum Number of Coins You Can Get (Leetcode Medium 1561)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, November, 2023
 * Method: Sort the piles, and then pick the second largest one each time
 * Result: Time complexity: O(nlogn), Space complexity: O(1)
 */

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int l = 0;
        int r = piles.size() - 1;
        int ans = 0;
        while (l < r) {
            l++;
            r--;
            ans += piles[r];
            r--;
        }
        return ans;
    }
};
