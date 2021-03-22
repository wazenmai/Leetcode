/**
 * Title:  Koko Eating Bananas (Leetcode Medium)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   22, Mar, 2021
 */

#define MAX_NUM 1000000001

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lnum = 1;
        int rnum = MAX_NUM;
        int size = piles.size();
        int ans = 1;
        int temp_h;

        while (lnum < rnum) {
            int mid = (lnum + rnum) / 2;
            // printf("%d, %d, %d ", lnum, mid, rnum);
            temp_h = 0;
            for (int i = 0; i < size; i++) {
                temp_h += piles[i] / mid + ((piles[i] % mid) ? 1 : 0);   
            }
            if (temp_h > h) {
                lnum = mid + 1;
                // printf("bigger\n");
            } else if (temp_h == h) {
                // printf("same\n");
                rnum = mid;
                ans = mid;
            } else {
                rnum = mid;
                ans = mid;
                // printf("smaller\n");
            }
        }
        return ans;
    }
};
