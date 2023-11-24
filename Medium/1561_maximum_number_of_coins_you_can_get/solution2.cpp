/**
 * Title:  Maximum Number of Coins You Can Get (Leetcode Medium 1561)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, November, 2023
 * Method: Add cpp optimization flags and fast io can reduce 50% runtime.
 * Result: Time complexity: O(nlogn), Space complexity: O(1)
 */

#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const auto fast = []() { std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0); return 0; } ();

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
