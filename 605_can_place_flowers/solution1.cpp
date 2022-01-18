/**
 * Title:  Can Place Flowers (Leetcode Easy 605)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   18, Jan, 2022
 */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int beds = flowerbed.size();
        if (n == 0)
            return true;
        int seats = 0;
        int ans = 0;
        int index = 0;
        if (flowerbed[0] == 0) {
            for (int i = 0; i < beds; i++) {
               if (flowerbed[i]) {
                   // cout << i << ": " << seats << "\n";
                   ans += seats / 2;
                   seats = 0;
                   index = i + 1;
                   break;
               } else {
                   seats++;
               }
            }
            if (index == 0)
                seats = 0;
        }
        
        for (int i = index; i < beds; i++) {
            if (flowerbed[i]) {
                // cout << i << ": " << seats << "\n";
                ans += (seats - 1) / 2;
                seats = 0;
            } else {
                seats++;
            }
        }
        if (flowerbed[beds-1] == 0) {
            // cout << beds << ": " << seats << "\n";
            if (beds == seats) {
                ans = (seats + 1) / 2;
            } else {
                ans += seats / 2;
            }
        }
        // cout << ans << "\n";
        if (ans < n)
            return false;
        return true;
    }
};
