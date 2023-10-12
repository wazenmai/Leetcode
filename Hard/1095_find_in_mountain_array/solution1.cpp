/**
 * Title:  Find in Mountain Array (Leetcode Hard 1095)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   12, October, 2023
 * Method: Use binary search to find the peak index, then search the target from left and right side.
 * Result: Time complexity O(3*logn). Space complexity O(1).
 */

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        // cout << "n: " << n << "\n";
        // Find peak
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (mid + 1 > n - 1)
                break;
            int num = mountainArr.get(mid);
            int next = mountainArr.get(mid + 1);
            if (num > next) {
                r = mid - 1;
            } else {
                if (num == target)
                    return mid;
                if (next == target)
                    return mid + 1;
                l = mid + 1;
            }
        }
        // cout << "peak " << l << ": " << mountainArr.get(l) << "\n";
        int peak = l;
        if (target == mountainArr.get(peak))
            return peak;
        
        // Find target from left side
        l = 0, r = peak;
        while (l < r) {
            int mid = (l + r) / 2;
            int num = mountainArr.get(mid);
            if (num == target) {
                return mid;
            } else if (num > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l < n && target == mountainArr.get(l))
            return l;
        
        // Find target from right side
        l = peak + 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            int num = mountainArr.get(mid);
            if (num == target) {
                return mid;
            } else if (num > target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        if (l < n && target == mountainArr.get(l))
            return l;
        return -1;
    }
};
