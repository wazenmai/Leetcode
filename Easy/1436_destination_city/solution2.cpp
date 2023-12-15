/**
 * Title:  Destination City (Leetcode Easy 1436)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, December, 2023
 * Method: Tidy up the code
 */

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> seen;
        for (auto& path: paths) {
            seen.emplace(path[0]);
        }
        for (auto& path: paths) {
            if (seen.find(path[1]) == seen.end())
                return path[1];
        }
        return "";
    }
};
