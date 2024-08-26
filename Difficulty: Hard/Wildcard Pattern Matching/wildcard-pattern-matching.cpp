//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int solve(int i, int j, string &pattern, string &str, vector<vector<int>> &dp){
        if(i == -1 && j == -1)
            return 1;
        if(i == -1)         // pattern end
            return 0;
        if(j == -1)         // str end
        {
            if(pattern[i] == '*')
                return solve(i - 1, j, pattern, str, dp);
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int res;
        if(pattern[i] == '?')
        {
            res = solve(i - 1, j - 1, pattern, str, dp);
        }
        else if(pattern[i] == '*')
        {
            // use * for current char only
            int res1 = solve(i, j - 1, pattern, str, dp);
            
            // use * also for next char
            int res2 = solve(i - 1, j - 1, pattern, str, dp);
            
            // skip *
            int res3 = solve(i - 1, j, pattern, str, dp);
            
            res = 0;
            if(res1 == 1 || res2 == 1 || res3 == 1)
                res = 1;
        }
        else
        {
            if(pattern[i] == str[j])
                res = solve(i - 1, j - 1, pattern, str, dp);
            else
                res = 0;
        }
        
        return dp[i][j] = res;
    }
    
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        int n1 = pattern.length();
        int n2 = str.length();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return solve(n1 - 1, n2 - 1, pattern, str, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends