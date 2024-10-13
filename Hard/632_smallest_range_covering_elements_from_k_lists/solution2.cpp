/**
 * Title:  Smallest Range Covering Elements from K Lists (Leetcode Hard 632)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   13, October, 2024
 * Method: Use min heap to store elements in range. Use a vector to store number of elements in range and next element to be added in each list. Everytime we increase left bound, we pop elements from heap and check whether to add the new element and adjust the right bound.
 * Result: Time complexity O(nklog(nk) + m) = O(50*3500*log(175000) + 1e5) ~~ 1e7. Space complexity O(nk).
 */

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (num, list id), number inside range.
        vector<vector<int>> check(n, vector<int>(2, 0)); // list id: (# in range, cur next id)
        int l = INT_MAX, r = INT_MIN; // range
        int maximum = INT_MIN;
        // Set initial window [l, r]
        for (int i = 0; i < n; i++) {
            l = min(l, nums[i][0]);
            r = max(r, nums[i][0]);
            maximum = max(maximum, nums[i].back());
        }
        // Add all elements between [l, r] in pq
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                if (nums[i][j] > r) break;
                if (nums[i][j] <= r) {
                    pq.push(make_pair(nums[i][j], i));
                    check[i][0]++;
                    check[i][1] = j + 1;
                }
            }
        }
        int range = r - l;
        int start = l;
        while (l < maximum) {
            // adjust left
            l++;
            bool out_of_range = false;
            while (!pq.empty() && pq.top().first < l) {
                auto [cur, id] = pq.top();
                check[id][0]--;
                if (check[id][0] == 0) {
                    if (check[id][1] == nums[id].size()) {
                        out_of_range = true;
                        break;
                    } else {
                        pq.push(make_pair(nums[id][check[id][1]], id));
                        r = max(r, nums[id][check[id][1]]);
                        check[id][0]++;
                        check[id][1]++;
                    }
                }
                pq.pop();
            }
            if (out_of_range) break;
            if (r - l < range) {
                range = r - l;
                start = l;
            }
        }
        return vector<int>{start, start + range};
    }
};
