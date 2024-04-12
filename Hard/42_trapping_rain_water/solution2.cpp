/**
 * Title:  Trapping Rain Water (Leetcode Hard 42)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, April, 2024
 * Method: Use two pointers to record the left and right walls. If one is heigher than another, it means the lower one can trap water.
 * Result: Time complexity is O(n), space complexity is O(1). n = height.size().
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lmax = -1, rmax = -1;
        int ans = 0;
        while (l < r) {
            lmax = max(height[l], lmax);
            rmax = max(height[r], rmax);
            // cout << "l(" << l << "): "<< lmax << "," << height[l] << ", r(" << r << "): " << rmax << "," << height[r] << " ans=";
            ans += (lmax < rmax) ? lmax - height[l++] : rmax - height[r--];
            // cout << ans << "\n";
        }
        return ans;
    }
};
