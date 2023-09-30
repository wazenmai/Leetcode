/**
 * Title:  132 Pattern (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   30, September, 2023
 * Method: Min array store i for every j, then find k from the right of nums, 
 *         use binary search to find k that is just greater than nums[i] (min_array[j]).
 * Result: O(NlogN) = O(N) find min array for i + O(NlogN) for binary search.
*/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // Binary search
        int n = nums.size();
        if (n < 3)
            return false;
        vector<int> min_array(n);
        min_array[0] = nums[0];
        for (int i = 1; i < n; i++)
            min_array[i] = min(min_array[i - 1], nums[i]);
        int k = n;
        for (int j = n - 1; j > 0; j--) {
            if (nums[j] <= min_array[j])
                continue;
            auto it = lower_bound(nums.begin() + k, nums.end(), min_array[j] + 1);
            k = it - nums.begin();
            if (k < n && nums[k] < nums[j])
                return true;
            nums[--k] = nums[j];
        }
        return false;
    }
};

/*
we can make use of Binary Search to directly find an element, which is just larger than min[j]min[j]min[j] in the required interval, if it exists. 
If such an element is found, we can compare it with nums[j]nums[j]nums[j] to check the 132 criteria. 
Otherwise, we continue the process as in the last approach.
*/
