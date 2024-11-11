/**
 * Title:  Prime Subtraction Operation (Leetcode Medium 2601)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, November, 2024
 * Method: The array should be strictly increasing. So iterate from n - 2-th element to 0-th, if it's smaller than previous value, continue, else, the smallest difference this number need to minus is nums[i] - nums[i + 1] + 1 (since it shoud be strictly increasing). Iterate this difference to nums[i], if we meet the prime, modify the number with this difference.
 * Result: Time complexity O(nmsqrt(m)) = O(nsqrt(m)) because we will soon meet a prime number in around 10 steps, Space complexity O(1).
 */

class Solution {
public:
    bool isPrime(int v) {
        if (v == 2) return true;
        if (!(v & 1) || v == 1) return false;
        for (int i = 2; i <= sqrt(v); i++) {
            if (v % i == 0) return false;
        }
        return true;
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i + 1] > nums[i]) continue;
            int diff = nums[i] - nums[i + 1] + 1;
            while (diff < 1000) {
                if (isPrime(diff)) break;
                if (diff >= nums[i]) break;
                diff++;
            }
            if (diff >= nums[i]) return false;
            nums[i] -= diff;
        }
        return true;
    }
};
