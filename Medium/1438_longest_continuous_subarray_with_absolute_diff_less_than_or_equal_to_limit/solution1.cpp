/**
 * Title:  Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit (Leetcode Medium 1438)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   23, June, 2024
 * Method: Use max_hep and min_heap to store the maximum and minimum values and index in the current window. Use two pointer sliding window to find the longest subarray. If the condition satisfies, move the right pointer to the right, otherwise move the left pointer to the right.
 * Result: Time complexity is O(nlogn), space complexity is O(n).
 */


typedef pair<int, int> pi; 

struct compare1 {
    bool operator()(pi& a, pi& b) {
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }
};


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 0;
        priority_queue<pi, vector<pi>, compare1> pq_max; // val, ind
        priority_queue<pi, vector<pi>, greater<pi>> pq_min; // val, ind
        while (r < n) {
            pq_max.push(make_pair(nums[r], r));
            pq_min.push(make_pair(nums[r], r));
            // cout << l << "," << r << ": " << pq_max.top().first << " " << pq_min.top().first << "\n";
            if (pq_max.top().first - pq_min.top().first <= limit) {
                ans = max(ans, r - l + 1);
                r++;
            } else {
                while (pq_max.top().first - pq_min.top().first > limit) {
                    l++;
                    while (pq_max.top().second < l)
                        pq_max.pop();
                    while (pq_min.top().second < l)
                        pq_min.pop();
                }
            }
        }
        return ans;
    }
};
