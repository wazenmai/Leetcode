/**
 * Title:  Number of Flowers in Full Bloom (Leetcode Hard 2251)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, October, 2023
 * Method: Sort the start, end time of flowers. Then use binary search to find the position of the people.
 * Result: n is the number of people, m is the number of flowers. 
 *         Time complexity O(mlogm + nlogm) = O((n+m)logm). Space complexity O(m).
 */

class Solution {
public:
    void printvec(vector<int>& v) {
        for (int& e: v) {
            cout << e << " ";
        }
        cout << "\n";
    }
    int bs(vector<int>& nums, int n, int target) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            }
        }
        return l;
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // 1. Sort the `start` and `end`
        int m = flowers.size();
        vector<int> start;
        vector<int> end;
        for (auto& flower: flowers) {
            start.emplace_back(flower[0]);
            end.emplace_back(flower[1] + 1);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> ans;
        for (int& p: people) {
            int s = bs(start, m, p);
            int e = bs(end, m, p);
            ans.emplace_back(s - e);
        }
        return ans;
    }
};
