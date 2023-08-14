/**
 * Title:  Kth Largest Element In An Array (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, August, 2023
 * Method: Use heap. Tme Complexity O(nlogk). Space Complexity O(k)
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap; // max-heap
        for (int num: nums) {
            heap.push(-num);
            if (heap.size() > k) { // leave k's smallest number (in real is biggest number)
                heap.pop();
            }
        }
        return -heap.top();
    }
};
