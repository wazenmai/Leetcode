/**
 * Title:  Triples with Bitwise AND Equal To Zero (Leetcode Hard 982)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, December, 2024
 * Method: Since we know the range is 2^16, we can restrict the range of the tuples to 2^16 and save the space and time.
 * Result: Time complexity O(n^2) or O(n^2 + n * 2^16), Space complexity O(n^2).
 */

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> tuples(1 << 16, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                tuples[nums[i] & nums[j]]++;
            }
        }
        for (const auto& num: nums) {
            for (int i = 0; i < (1 << 16); i++) {
                if ((i & num) == 0) ans += tuples[i];
            }
        }
        return ans;
    }
};

// dp[i] = # of triples that bitwise-AND = 0 from nums[0 ~ i]
// at most 16 bits
