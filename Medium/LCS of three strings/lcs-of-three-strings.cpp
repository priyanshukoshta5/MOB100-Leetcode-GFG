//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            int dp[21][21][21] = {0};
            
            for(int i = n1 - 1; i >= 0; i--)
            {
                for(int j = n2 - 1; j >= 0; j--)
                {
                    for(int k = n3 - 1; k >= 0; k--)
                    {
                        if(A[i] == B[j] && B[j] == C[k])
                            dp[i][j][k] = 1 + dp[i + 1][j + 1][k + 1];
                        else
                            dp[i][j][k] = max(dp[i + 1][j][k], 
                                            max(dp[i][j + 1][k], dp[i][j][k + 1]));
                    }
                }
            }
            
            return dp[0][0][0];
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends