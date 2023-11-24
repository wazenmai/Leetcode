/**
 * Title:  Maximum Number of Coins You Can Get (Leetcode Medium 1561)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, November, 2023
 * Method: After observation, we can find the answer is count from n / 3 index with step 2
 * Result: Time complexity: O(nlogn), Space complexity: O(1)
 */

#pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
static const auto fast = []() { std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0); return 0; } ();

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int ans = 0;
        for (int i = n / 3; i < n; i += 2) {
            ans += piles[i];
        }
        return ans;
    }
};

// 1 2 3 4 5 6 7 8 9
// 8 6 4
