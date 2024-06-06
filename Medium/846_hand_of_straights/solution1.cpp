/**
 * Title:  Hand of Straights (Leetcode Medium 846)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, June, 2024
 */

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        
        map<int, int> m;
        for (auto& num: hand) {
            m[num]++;
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            int num = it->first;
            int cnt = it->second;
            // cout << "(" << num << "," << cnt << ")\n";
            while (cnt > 0) {
                for (int i = 1; i < groupSize; i++) {
                    if (m[num + i] > 0) {
                        m[num + i]--;
                    } else {
                        return false;
                    }
                }
                m[num]--;
                cnt--;
            }
        }
        return true;
    }
};
