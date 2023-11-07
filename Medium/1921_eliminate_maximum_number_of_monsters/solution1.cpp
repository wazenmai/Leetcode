/**
 * Title:  Eliminate Maximum Number of Monsters (Leetcode Medium 1921)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   07, November, 2023
 * Method: Arrive to city time = distance / speed + (distance % speed ? 1 : 0). So we can sort this array to get the order of monster entering city.
 * Result: Time complexity O(nlogn), Space complexity O(n)
 */

class Solution {
public:
    void print(vector<int>& v) {
        for (auto& e: v) {
            cout << e << " ";
        }
        cout << "\n";
    }
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n);
        for (int i = 0; i < n; i++) {
            time[i] = dist[i] / speed[i];
            if (dist[i] % speed[i])
                time[i]++;
        }
        sort(time.begin(), time.end());
        // print(time);
        int ans = 1;
        int now = 1;
        for (int i = 1; i < n; i++) {
            if (time[i] > now) {
                ans++;
                now++;
            } else {
                break;
            }
        }
        return ans;
    }
};
