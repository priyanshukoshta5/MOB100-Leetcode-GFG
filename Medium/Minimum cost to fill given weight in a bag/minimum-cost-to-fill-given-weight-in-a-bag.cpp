//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  private:
    int solve(int n, int w, vector<int> &cost, vector<vector<int>> &dp){
        if(w == 0)
            return 0;
        if(n == 0)
            return 1e8;
        if(dp[n][w] != -1)
            return dp[n][w];
        
        // notTake
        int notTake = solve(n - 1, w, cost, dp);
        
        // take
        int take = 1e8;
        if(n <= w && cost[n - 1] >= 0)
            take = cost[n - 1] + solve(n, w - n, cost, dp);
        
        return dp[n][w] = min(take, notTake);
    }
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        vector<vector<int>> dp(n + 1, vector<int> (w + 1, -1));
        int res = solve(n, w, cost, dp);
        return (res >= 1e8) ? -1 : res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends