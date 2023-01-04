/**
 * Title:  Minimum Rounds to Complete All Tasks (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, Janurary, 2022
 */

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> m;
        int ans = 0;
        for (auto& task: tasks) {
            if (m.find(task) == m.end()) {
                m.insert({task, 1});
            } else {
                m.at(task) += 1;
            }
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) {
                return -1;
            } else {
                ans += countRounds(it->second);
            }  
        }
        return ans;
    }

    int countRounds(int num) {
        if (num == 2 || num == 3) {
            return 1;
        } else if (num == 4){
            return 2;
        } 
        int count = num / 3;
        if (num % 3 == 0) {
            return count;
        }
        return count + 1;
    }

    /* recursion 
    int countRounds(int num) {
        if (num == 2 || num == 3) {
            return 1;
        } else if (num == 4){
            return 2;
        } else {
            return 1 + countRounds(num - 3);
        }
        return 0;
    }
    */
};
