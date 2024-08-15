/**
 * Title:  Lemonade Change (Leetcode Easy 850)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   15, August, 2024
 */

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for (auto& bill: bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five < 1) return false;
                ten++;
                five--;
            } else { // bill = 20
                if (ten >= 1 && five >= 1) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
                twenty++;
            }
        }
        return true;
    }
};
