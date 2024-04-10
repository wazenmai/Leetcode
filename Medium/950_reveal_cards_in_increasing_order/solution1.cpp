/**
 * Title:  Reveal Cards In Increasing Order (Leetcode Medium 950)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   10, April, 2024
 * Method: Use queue to simulate the process by recording the index of the cards.
 * Result: Time complexity is O(nlogn), space complexity is O(n). n = deck.size().
 */

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        queue<int> q;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        int i = 0;
        while (!q.empty()) {
            // revealed
            int out = q.front();
            q.pop();
            ans[out] = deck[i];
            i++;
            // queue back
            if (q.empty()) break;
            int back = q.front();
            q.pop();
            q.push(back);
        }
        return ans;
    }
};

// 0 10 1 15 2 11 3x4 12 5 16 6 13 7 x 8  14  9. 17 (end: start=7->rotate, step=8, i=18) fill 3
// 0 10 1 x 2 11 3x 4 12 5 x 6 13 7  x  8. 14  9  x (end: start=3, step=8, i=15) fill 5 
// 0 x 1 x 2 x 3 x 4 x 5  x. 6. x. 7. x. 8. x. 9. x. (end: start=1, step=4, i=10) fill 10
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 (n = 20)
// 0 a 1 b 2 c 3 d 4 e  5. f. 6. g. 7  h. 8. i  9. j, step=2
// abcdefghij -> 10b11d12f13h14j (n = 10), step=4
// bdfhj -> 15d16h17 (n = 5), step=8
// hd -> 18 19, step=8


// 0 1 2 3 4 5 6 7 8 9 10 (n = 11) start=0, step=2, i=0, fill 6=(剩餘長度+1)/2
// 0 a 1 b 2 c 3 d 4 e 5 -> bcdea (n = 5), step=4, i=6, fill 3
// 6c7e8 -> ec (n=2), step=8
