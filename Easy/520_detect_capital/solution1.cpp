/**
 * Title:  Detect Capital (Leetcode Easy 520)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   24, Jan, 2022
 * Result: Runtime 0ms, Memory Usage 6 MB
 */

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        bool big = false;
       
        if (n == 1)
            return true;
        
        if (word[0] <= 'Z' && word[1] <= 'Z')
            big = true;
        for (int i = 1; i < n; i++) {
            if (!big && word[i] <= 'Z')
                return false;
            if (big && word[i] >= 'a')
                return false;
        }
        return true;
    }
};
