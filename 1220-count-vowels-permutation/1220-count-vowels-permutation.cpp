class Solution {
private:
    int MOD = 1e9+7;
    map<char, int> code = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};

    long long int solve(char ch, int n, vector<vector<long long int>> &dp){
        if(n == 0)
            return 1LL;
        if(dp[n][code[ch]] != -1)
            return dp[n][code[ch]];
        
        long long int count = 0;
        if(ch == 'a'){
            count = count + (solve('e', n - 1, dp) % MOD);
        }
        else if(ch == 'e'){
            count = count + (solve('a', n - 1, dp) % MOD) 
                          + (solve('i', n - 1, dp) % MOD);
        }
        else if(ch == 'i'){
            count = count + (solve('a', n - 1, dp) % MOD) 
                          + (solve('e', n - 1, dp) % MOD)
                          + (solve('o', n - 1, dp) % MOD) 
                          + (solve('u', n - 1, dp) % MOD);
        }
        else if(ch == 'o'){
            count = count + (solve('i', n - 1, dp) % MOD) 
                          + (solve('u', n - 1, dp) % MOD);
        }
        else if(ch == 'u'){
            count = count + (solve('a', n - 1, dp) % MOD);
        }

        return dp[n][code[ch]] = count % MOD;
    }

public:
    int countVowelPermutation(int n) {
        vector<vector<long long int>> dp(n, vector<long long int> (5, -1));
        long long int a = solve('a', n - 1, dp);
        long long int e = solve('e', n - 1, dp);
        long long int i = solve('i', n - 1, dp);
        long long int o = solve('o', n - 1, dp);
        long long int u = solve('u', n - 1, dp);
        return (a + e + i + o + u) % MOD;
    }
};