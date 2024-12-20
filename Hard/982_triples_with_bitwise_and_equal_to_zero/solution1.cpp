/**
 * Title:  Triples with Bitwise AND Equal To Zero (Leetcode Hard 982)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, December, 2024
 * Method: Brute Force. But we can use hash table to store the tuples of bitwise-AND of two numbers, and then traverse the array to find the triples that bitwise-AND equals to 0.
 * Result: Time complexity O(n^2) or O(n^2 + n * 2^16), Space complexity O(n^2).
 */

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> tuples;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tuples[nums[i] & nums[j]]++;
            }
        }
        for (const auto& num: nums) {
            for (auto t: tuples) {
                if ((t.first & num) == 0) ans += t.second;
            }
        }
        return ans;
    }
};

// dp[i] = # of triples that bitwise-AND = 0 from nums[0 ~ i]
// at most 16 bits