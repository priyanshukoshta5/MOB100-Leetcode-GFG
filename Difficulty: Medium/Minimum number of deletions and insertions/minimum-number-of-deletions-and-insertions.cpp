//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	private:
	int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
	    if(i == -1 && j == -1)
	        return 0;
	    if(i == -1 || j == -1)
	        return max(i + 1, j + 1);
	    if(dp[i][j] != -1)
	        return dp[i][j];
	    
	    int res = 1e5;
	    if(s1[i] == s2[j])
	        res = solve(i - 1, j - 1, s1, s2, dp);
	    else
	        res = 1 + min(solve(i - 1, j, s1, s2, dp), solve(i, j - 1, s1, s2, dp));
	    
	    return dp[i][j] = res;
	}

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int n1 = str1.size();
	    int n2 = str2.size();
	    vector<vector<int>> dp(n1, vector<int> (n2, -1));
	    return solve(n1 - 1, n2 - 1, str1, str2, dp);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends