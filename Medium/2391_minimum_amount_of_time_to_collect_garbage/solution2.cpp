/**
 * Title:  Minimum Amount of Time to Collect Garbage (Leetcode Medium 2391)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   20, November, 2023
 * Method: Combine calculation in one loop
 * Result: Time complexity O(n), space complexity O(1)
 */

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();
        int ans = 0;
        int m_temp = 0;
        int g_temp = 0;
        int p_temp = 0;
        bool m_flag, g_flag, p_flag;
        for (int i = 0; i < n; i++) {
            m_flag = g_flag = p_flag = false;
            for (char& c: garbage[i]) {
                if (c == 'M') {
                    m_flag = true;
                } else if (c == 'G') {
                    g_flag = true;
                } else {
                    p_flag = true;
                }
                ans += 1;
            }
            if (m_flag) {
                m_flag = false;
                ans += m_temp;
                m_temp = 0;
            }

            if (g_flag) {
                g_flag = false;
                ans += g_temp;
                g_temp = 0;
            }

            if (p_flag) {
                p_flag = false;
                ans += p_temp;
                p_temp = 0;
            }

            if (i < n - 1) {
                m_temp += travel[i];
                g_temp += travel[i];
                p_temp += travel[i];
            }
        }
        return ans;
    }
};
