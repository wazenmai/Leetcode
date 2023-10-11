/**
 * Title:  Number of Flowers in Full Bloom (Leetcode Hard 2251)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, October, 2023
 * Method: Use map to record the difference of start and end time of flowers. Then use positions to record those important position and 
 *         the prefix to record the flower in bloom at that position. Then use binary search to find the position of the people.
 * Result: n is the number of people, m is the number of flowers. Time complexity O(mlogm + m + nlogm) = O((n+m)logm). Space complexity O(m)
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
        map<int, int> difference;
        difference[0] = 0;
        for (auto& flower: flowers) {
            difference[flower[0]]++;
            difference[flower[1] + 1]--;
        }

        vector<int> positions;
        vector<int> prefix;
        int flower = 0;
        for (auto& pair: difference) {
            positions.emplace_back(pair.first);
            flower += pair.second;
            prefix.emplace_back(flower);
        }
        // printvec(positions);
        // printvec(prefix);
        vector<int> ans;
        int m = positions.size();
        for (int& p: people) {
            int up = bs(positions, m, p);
            int i = up - 1;
            ans.emplace_back(prefix[i]);
        }
        return ans;
    }
};
