/**
 * Title:  Maximum XOR of 2 numbers in Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   27, Jan, 2022
 * Result: TLE
 */
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maximum = 0;
        int n = (int)nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // cout << "(" << i << ", " << j << "): " << (nums[i] ^ nums[j]) << "\n";
                if ((nums[i] ^ nums[j]) > maximum)
                    maximum = nums[i] ^ nums[j];
            }
        }
        return maximum;
    }
};
