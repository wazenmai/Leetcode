/**
 * Title:  Poor Pigs (Leetcode Hard 458)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   29, October, 2023
 * Method: We can use minutesToTest / minutesToDie + 1 -> carry to encode the bucket number. Note that we need to deal with the error of double.
 * Result: Time Complexity O(1), Space Complexity O(1)
 */

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ans = buckets / (int)(minutesToTest / minutesToDie);
        int carry = minutesToTest / minutesToDie + 1;
        double num = log(buckets) / log(carry);
        // cout << "base_ans " << ans << "\ncarry: " << carry << "\n";
        // double flag = num - floor(num);
        // cout << num << " " << floor(num) << " " << flag << "\n";
        if (num - floor(num) < 1e-15) {
            ans = min(ans, (int)num);
        } else {
            ans = min(ans, (int)num + 1);
        }
        return ans;
    }
};
