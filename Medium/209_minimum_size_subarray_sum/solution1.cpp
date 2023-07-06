/**
 * Title:  Minimum Size Subarray Sum (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, July, 2023
 * Method: Find window from length 2 to n
 * Result: TLE. Time Complexity O(n^2)
 */


class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int)nums.size();
        int sum = 0;
        vector<int> add;
        add.emplace_back(0);
        for (int num: nums) {
            if (num >= target)
                return 1;
            sum += num;
            add.emplace_back(sum);
        }
        if (sum == target)
            return n;
        if (sum < target)
            return 0;
        
        // print
        for (int num: add) {
            cout << num << " ";
        }
        cout << endl;

        int length = 2;
        while (length <= n) {
            for (int i = 0; i < n - length + 1; i++) {
                if (add[i + length] - add[i] >= target)
                    return length;
            }
            ++length;
        }
        
        return 0;
    }
};