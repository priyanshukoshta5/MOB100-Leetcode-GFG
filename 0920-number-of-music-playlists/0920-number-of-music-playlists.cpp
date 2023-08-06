// Thanks NeetCode YT

class Solution {
private:
    int MOD = 1e9+7;

    long long findPlaylists(int cur_goal, int old_songs, int n, int k, vector<vector<long long>> &dp){
        if(cur_goal == 0 && old_songs == n)
            return 1;
        if(cur_goal == 0 || old_songs > n)
            return 0;
        if(dp[cur_goal][old_songs] != -1)
            return dp[cur_goal][old_songs];

        long long res = 0;
        // Choose new song
        res = (n - old_songs) * findPlaylists(cur_goal - 1, old_songs + 1, n, k, dp);
        res = res % MOD;

        if(old_songs > k)   // can only choose if count of old songs is > k
        {
            // Choose old song
            long long temp = (old_songs - k) * findPlaylists(cur_goal - 1, old_songs, n, k, dp) % MOD;
            temp = temp % MOD;
            res = (res + temp) % MOD;
        }

        return dp[cur_goal][old_songs] = res;
    }

public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(goal + 1, vector<long long> (n + 1, -1));
        return findPlaylists(goal, 0, n, k, dp);
    }
};