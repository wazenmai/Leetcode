/**
 * Title:  Number of Flowers in Full Bloom (Leetcode Hard 2251)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   11, October, 2023
 * Method: Sort the start, end time of flowers and the people array. Then use start_idx and end_idx to record the current flower in bloom.
 * Result: n is the number of people, m is the number of flowers. Time complexity O(nlogn + mlogm + n) = O(nlogn + mlogm), Space complexity O(n + m)
 */

class Solution {
public:
    void printvec(vector<int>& v) {
        for (int& e: v)
            cout << e << " ";
        cout << "\n";
    }
    void printpair(vector<pair<int, int>>& v) {
        for (auto& e: v)
            cout << "(" << e.first << "," << e.second << ") ";
        cout << "\n";
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = people.size();
        int m = flowers.size();
        vector<int> start;
        vector<int> end;
        for (auto& flower: flowers) {
            start.emplace_back(flower[0]);
            end.emplace_back(flower[1]);
        }
        vector<pair<int, int>> new_people;
        for (int i = 0; i < n; i++) {
            new_people.emplace_back(make_pair(people[i], i));
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        sort(new_people.begin(), new_people.end());
        // printvec(start);
        // printvec(end);
        // printpair(new_people);

        vector<int> ans(n);
        int flower = 0;
        int start_idx = 0;
        int end_idx = 0;
        for (auto& p: new_people) {
            while (start_idx < m && start[start_idx] <= p.first) {
                flower++;
                start_idx++;
            }
            while (end_idx < m && end[end_idx] < p.first) {
                flower--;
                end_idx++;
            }
            ans[p.second] = flower;
        }
        return ans;
    }
};

// 1 3 4 9
// 6 7 12 13
// 2 3 7 11