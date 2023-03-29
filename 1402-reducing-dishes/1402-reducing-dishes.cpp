class Solution {
private:
    int solve(vector<int>& stfn, int index, int cur_pos, vector<vector<int>>& dp){
        // If no more dishes are left
        if(index == stfn.size())
            return 0;
        
        // If already calculated
        if(dp[index][cur_pos] != -1)
            return dp[index][cur_pos];
        
        int ans = INT_MIN;
        
        // Selecting the dish
        ans = max(ans, stfn[index]*cur_pos + solve(stfn, index+1, cur_pos+1, dp));
        
        // Skipping the dish
        ans = max(ans, solve(stfn, index+1, cur_pos, dp));
        
        return dp[index][cur_pos] = ans;
    }
    
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        
        int index = 0;
        int cur_pos = 1;
        return max(0, solve(satisfaction, index, cur_pos, dp));
    }
};