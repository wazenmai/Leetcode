/**
 * Title:  Rearrange Array Elements By Sign (Leetcode Medium 2149)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   14, February, 2024
 * Method: Using two queues to store positive and negative numbers, and then pop them out to form the answer array inside one loop.
 * Result: Time complexity O(n), Space complexity O(n)
 */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        queue<int> q_negative;
        queue<int> q_positive;
        for (int& num: nums) {
            if (ans.size() == 0) {
                if (num > 0) ans.emplace_back(num);
                else q_negative.push(num);
            } else {
                if (num > 0) {
                    if (ans.back() < 0) {
                        if (q_positive.empty()) {
                            ans.emplace_back(num);
                        } else {
                            ans.emplace_back(q_positive.front());
                            q_positive.pop();
                            q_positive.push(num);
                        }
                    } else {
                        q_positive.push(num);
                    }
                } else {
                    if (ans.back() > 0) {
                        if (q_negative.empty()) {
                            ans.emplace_back(num);
                        } else {
                            ans.emplace_back(q_negative.front());
                            q_negative.pop();
                            q_negative.push(num);
                        }
                    } else {
                        q_negative.push(num);
                    }
                }
            }
        }
        while (!q_positive.empty() || !q_negative.empty()) {
            if (ans.back() > 0) {
                ans.emplace_back(q_negative.front());
                q_negative.pop();
            } else {
                ans.emplace_back(q_positive.front());
                q_positive.pop();
            }
        }
        return ans;
    }
};
