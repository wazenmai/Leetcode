/**
 * Title:  Bag of Tokens (Leetcode Medium 948)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   04, March, 2024
 */


class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int best = 0;
        int left = 0;
        int right = tokens.size() - 1;
        while (left <= right) {
            if (power >= tokens[left]) {
                score++;
                power -= tokens[left];
                // cout << "up " << left << "," << tokens[left] << "\n";
                best = max(best, score);
                left++;
            } else if (score >= 1){
                power += tokens[right];
                // cout << "down " << right << "," << tokens[right] << "\n";
                score--;
                right--;
            } else {
                break;
            }
        }
        return best;
    }
};
