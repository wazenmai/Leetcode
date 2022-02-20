/**
 * Title:  Minimize Deviation in Array (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, Feb, 2022
 * Method: First turn array to the state "Biggest", use heap to find maximum and so on.
 */

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = (int)nums.size();
        int min_num = 1000000000;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            if (nums[i] & 1)
                nums[i] = nums[i] << 1;
            pq.push(nums[i]);
            min_num = min(min_num, nums[i]);
        }
        int deviation = pq.top() - min_num;
        while (!(pq.top() & 1)) {
            int temp = pq.top() >> 1;
            pq.pop();
            pq.push(temp);
            min_num = min(temp, min_num);
            deviation = min(deviation, pq.top() - min_num);
        }
        return deviation;
    }
};
