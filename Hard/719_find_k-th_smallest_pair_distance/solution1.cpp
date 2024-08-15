/**
 * Title:  Find K-th Smallest Pair Distance (Leetcode Hard 719)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, August, 2024
 * Method: Binary search the distance that satisfy kth smallest among all pairs.
 *         Given maxDistance, count the number of pairs that have distance <= maxDistance -> sliding window. 
 *         Iterate through left pointer i, find the right pointer j that satisfy nums[j] - nums[i] <= maxDistance. The number of pairs is j - i - 1 since j is on the valid right point + 1.
 * Result: Time complexity is O(nlogn), space complexity is O(1).
 */

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        // Binary search the distance that satisfy kth smallest among all pairs
        int l = 0, r = nums.back() - nums[0];
        int n = nums.size();
        
        function<bool(int)> check = [&](int maxDistance) {
            int cnt = 0, j = 0;
            for (int i = 0; i < n; i++) {
                while (j < n && nums[j] - nums[i] <= maxDistance) j++;
                cnt += j - i - 1;
            }
            return cnt >= k;
        };
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r + 1;
    }
};

// Binary Search
// 左右界 (l, r)
// - [l, r] -> 條件為 while (l <= r) // 因為 l == r 時還有答案
//      - check(mid) = true: r = mid - 1 or l = mid + 1 // 因為 mid 已檢查過
//      - ans = r + 1 // 因為當 mid 符合條件時，mid 為當次最佳答案，r = mid - 1 -> mid = r + 1
// - [l, r) -> 條件為 while (l < r) // 因為 l == r 時無答案
//      - check(mid) = true: r = mid or l = mid + 1 // 右開開因此 r = mid (反正不會再用到)，左閉因此 l = mid + 1 (mid 已檢查)
