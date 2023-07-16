/**
 * Title:  Smallest Sufficient Team (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   16, July, 2023
 * Method: DP + Bitmask. Time Complexity: O(N * 2^M), Space Complexity: O(2^M). N = # people, M = # skills
 */

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> d;
        vector<int> new_people(people.size(), 0);
        for (int i = 0; i < (int)req_skills.size(); i++) {
            d[req_skills[i]] = i;
        }
        
        int req_skill = (1 << (int)req_skills.size());
        for (int i = 0; i < (int)people.size(); i++) {
            for (auto skill: people[i]) {
                new_people[i] |= 1 << d[skill];
            }
        }

        vector<int> dp(req_skill, 0x3f3f3f3f);
        vector<long long int> status(req_skill, 0); // which person in team
        dp[0] = 0; // no skills, no people
        for (int i = 0; i < (int)new_people.size(); i++) {
            for (int j = 0; j < req_skill; j++) {
                if (dp[j] + 1 < dp[j| new_people[i]]) { // choose the person
                    dp[j| new_people[i]] = dp[j] + 1;
                    status[j| new_people[i]] = status[j] | (1LL << i); // 1LL = (long long)1
                }
            }
        }
        // cout << dp[req_skill - 1] << " " << status[req_skill - 1];
        vector<int> ans;
        int num = 0;
        while (status[req_skill - 1] > 0) {
            if (status[req_skill - 1] % 2)
                ans.emplace_back(num);
            status[req_skill - 1] /= 2;
            ++num;
        }
        return ans;
    }
};

/*
dp[bag]: when we have skills in bag, the minimum people we need
status[bag]: when we have skills in bag, which people in team now
goal: dp[req_skill - 1], status[req_skill - 1]
*/
