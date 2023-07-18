//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        int solve(int i, int j, string& str, vector<vector<int>> &dp){
            if(i < 0 || j < 0)
                return 0;
            if(dp[i][j] != -1)
                return dp[i][j];
            
            if(i != j && str[i] == str[j])
                return dp[i][j] = 1 + solve(i-1, j-1, str, dp);
            else
                return dp[i][j] = max(solve(i-1, j, str, dp), solve(i, j-1, str, dp));
        }

	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.length();
		    vector<vector<int>> dp(n, vector<int> (n, -1));
		    return solve(n-1, n-1, str, dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends