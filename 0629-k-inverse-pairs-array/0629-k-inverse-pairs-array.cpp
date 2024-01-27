// ~ MarkSPhilip31

class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {1};  
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int x = 0; x <= min(j, i - 1); x++) {
                    
                    if (j - x >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % 1000000007;
                    }
                }
            }
        }

        return dp[n][k];
    }
};




// class Solution {
// private:
//     int MOD = 1e9+7;
//     int solve(int n, int k){
//         if(k == 0 || n == 0 || n == k)
//             return 1;

//         return (solve(n - 1, k) + solve(n, k - 1)) % MOD;
//     }

// public:
//     int kInversePairs(int n, int k) {
//         return solve(n, k);
//     }
// };