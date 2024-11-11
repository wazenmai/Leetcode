/**
 * Title:  Prime Subtraction Operation (Leetcode Medium 2601)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, November, 2024
 * Method: Construct sieve array first, which record whether this number is prime or not. O(mloglog(m)). Then iterate the array from curVal = 1.
 * Result: Time complexity O(n + mloglogm), Space complexity O(m).
 */

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int max_num = *max_element(nums.begin(), nums.end());

        vector<int> sieve(max_num + 1, 1);
        sieve[1] = 0;
        for (int i = 2; i <= sqrt(max_num + 1); i++) {
            if (sieve[i] == 1) {
                for (int j = i * i; j <= max_num; j += i) {
                    sieve[j] = 0;
                }
            }
        }

        int cur = 1;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            int diff = nums[i] - cur;
            if (diff < 0) {
                return false;
            }

            if (sieve[diff] || diff == 0) {
                i++;
                cur++;
            } else {
                cur++;
            }
        }
        return true;
    }
};
