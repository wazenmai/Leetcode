/**
 * Title:  Boats to Save People (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, Mar, 2022
 */

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = (int)people.size() - 1;
        int ans = 0;
        while (people[j] == limit) {
            // cout << ans << ": (" << people[j] << ")\n"; 
            j--;
            ans++;
        }
        // cout << ans << ": (";
        while (i <= j) {
            if (i == j) {
                // cout << people[i] << ")\n";
                ans++;
                break;
            }
            if (people[i] + people[j] > limit) {
                // cout << people[j] << ")\n";
                ans++;
                // cout << ans << ": (";
                j--;
            } else if (people[i] + people[j] <= limit) {
                // cout << people[i] << ", " << people[j] << ")\n";
                i++;
                j--;
                ans++;
                // cout << ans << ": (";
            }
        }
        return ans;
    }
};