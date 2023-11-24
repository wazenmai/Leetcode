/**
 * Title:  Maximum Number of Coins You Can Get (Leetcode Medium 1561)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, November, 2023
 * Method: Use hash table to store the number of piles, and then pick the second largest one each time
 * Result: Time complexity: O(n), Space complexity: O(n)
 */

// #pragma GCC optimize("Ofast","inline","ffast-math","unroll-loops","no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")
// static const auto fast = []() { std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0); return 0; } ();

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int arr[100001] = {0};
        int l = 0;
        int r = -1;
        for (auto& pile: piles) {
            arr[pile]++;
            r = max(r, pile);
        }
        int ans = 0;
        while (l <= r) {
            // find Bob
            while (arr[l] == 0 && l <= r) {
                l++;
            }
            // cout << "Bob: " << l << ", ";
            arr[l]--;
            // find Alice
            while (arr[r] == 0 && l <= r) {
                r--;
            }
            arr[r]--;
            // cout << "Alice: " << r << ", ";
            // find Me
            while (arr[r] == 0 && l <= r) {
                r--;
            }
            // cout << "Me: " << r << "\n";
            if (arr[r] > 0)
                ans += r;
            arr[r]--;
        }
        return ans;
    }
};
