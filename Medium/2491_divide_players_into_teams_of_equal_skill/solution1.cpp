/**
 * Title:  Divide Players Into Teams of Equal Skill (Leetcode Medium 2491)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, October, 2024
 */

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        int l = 0, r = n - 1;
        int partial_sum = skill[l] + skill[r];
        long long ans = 0;
        while (l < r) {
            if (skill[l] + skill[r] != partial_sum) return -1;
            ans += skill[l] * skill[r];
            l++;
            r--;
        }
        return ans;
    }
};

// 1 2 3 3 4 5

