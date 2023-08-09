/**
 * Title:  Minimize the Maximum Difference of Pairs (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   09, August, 2023
 * Method: Binary search to guess the minimizeMax, then use greedy to find the pairs. Time complexity: O(nlogn), Space complexity: O(1)
 */

class Solution {
private:
    int n;
    int goal;
public:
    int printVec(vector<int>& nums) {
        int max_num = 0;
        for (int num: nums) {
            // cout << num << " ";
            max_num = max(max_num, num);
        }
        // cout << "\n";
        return max_num;
    }
    int numPairs(vector<int>& nums, int diff) {
        int i = 1;
        int pair = 0;
        while (i < n) {
            if (nums[i] - nums[i - 1] <= diff) {
                pair++;
                i += 2;
            } else {
                i += 1;
            }
            if (pair >= goal)
                return pair;
        }
        // cout << "guess " << diff << ": " << pair << "\n";
        return pair;
    }
    int minimizeMax(vector<int>& nums, int p) {
        n = nums.size();
        goal = p;
        sort(nums.begin(), nums.end());
        int r = printVec(nums);
        int l = 0;
        // use binary search guess minimizeMax
        while (l < r) {
            int mid = (l + r) / 2;
            if (numPairs(nums, mid) >= p) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
