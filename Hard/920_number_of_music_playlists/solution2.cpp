/**
 * Title:  Number of Music Playlists (Leetcode Hard)
 * Author: Bronwin Chen <iotbwu0101@gmail.com>
 * Date:   06, August, 2023
 * Method: Top-Down DP, Time Complexity: O(goal * n), Space Complexity: O(goal * n)
 */

class Solution {
private:
    const int modulo = 1000000007;
public:
    int countPlaylist(int n, int k, int i, int j, vector<vector<int>>& dp) {
        // i = length of playlist, j = # unique songs
        if (j == 0 && i != 0)
            return 0;
        if (i < j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int add_new_song = (int)((countPlaylist(n, k, i - 1, j - 1, dp) * (long long)(n - j + 1)) % modulo);
        int replay_old_song = 0;
        // replay old song
        if (j > k) {
            replay_old_song = (int)((countPlaylist(n, k, i - 1, j, dp) * (long long)(j - k)) % modulo);
        }
        long long ans = (add_new_song + replay_old_song) % modulo;
        return dp[i][j] = (int)ans;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        long long int ans = 1;
        if (n == goal || k == n - 1) {
            ans = 1;
            while (n != 1) {
                ans = (ans * n) % modulo;
                n--;
            }
            return ans;
        }

        vector<vector<int>> dp(goal+1, vector<int>(n+1, -1));
        dp[0][0] = 1; // empty list
        return countPlaylist(n, k, goal, n, dp);
    }
};

/* Top-Down DP */

/* Bottom-Up DP */
// State: dp[i][j]: # possible playlists of length i containing j unique songs
// Goal: dp[goal][n]
// Base case: dp[0][0] = 1 (empty list), for i < j, dp[i][j] = 0
// Transition: 
    // Add a song: dp[i][j] <- dp[i-1][j-1] # we have n - (j - 1) songs to add, so we have dp[i-1][j-1]*(n-j+1) choice to add
    // Replay an old song: dp[i][j] <- dp[i-1][j] # we have j unique songs, and we can't choose last k played songs, so we have j - k (if j > k) choices, so we can add dp[i-1][j] * (j-k)
// Time complexity: O(goal * n)
// Sapce complexity: O(goal * n)


// n = 2, goal = 3, k = 0
// [1,2,1] [1,2,2] [2,1,1] [2,1,2] + [1,1,2], [2,2,1]
// n = 2, goal = 4, k = 0
// 上面的 6 * 2(n) + [1,1,1,2], [2,2,2,1]
// n = 2, goal = 5, k = 0
// 上面的 14*2 = 28 + [1,1,1,1,2], [2,2,2,2,1]

// ---
// n = 3, goal = 3, k = 1, ans = 6
// [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].
// n = 3, goal = 4, k = 1, ans = 6*2 + 6
// 6 * 2 + 6 (1取代3補3, 1取代2補2) = 18 [1,2,1,3] [1,3,1,2] [2,1,2,3] [2,3,2,1]
// [3,1,3,2] [3,2,3,1]
// n = 3, goal = 5, k = 1
// 18*2 [1,2,1,2] [2,1,2,1] +6, ans = 18*3 + 6

// n = 4, goal = 4, k = 2, ans = 24
// n = 4, goal = 5, k = 2, 24*3+24 = 72
// n = 4, goal = 6, k = 2, 72*3 + 24 
