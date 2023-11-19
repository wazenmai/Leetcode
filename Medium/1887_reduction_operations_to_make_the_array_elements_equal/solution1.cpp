/**
 * Title:  Reduction Operations to Make the Array Elements Equal (Leetcode Medium 1887)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   19, November, 2023
 * Method: Use map to count the number of each element, the # of operations is the sum of the number of each element * the level of the element.
    * level = the order of the number, which is the # of operations it need to reduce.
 * Result: Time complexity O(nlogn), space complexity O(n)
 */

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int, int> m;

        for (int& num: nums) {
            m[num]++;
        }        

        if (m.size() == 1) return 0;

        int ans = 0;
        int level = 1;
        bool flag = true;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (flag) {
                flag = false;
                continue;
            }
            ans += (level * it->second);
            level++;
        }
        return ans;
    }
};
