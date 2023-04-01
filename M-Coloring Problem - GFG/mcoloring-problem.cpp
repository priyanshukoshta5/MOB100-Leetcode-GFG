//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
private:
    bool isSafe(int node, vector<int>& color, bool graph[101][101], int n, int col) {
        for (int k = 0; k < n; k++) 
            if (k != node && graph[k][node] == 1 && color[k] == col)
                return false;
        return true;
    }

    bool solve(bool graph[101][101], int n, int m, int node, vector<int>& color){
        if(node == n)
            return true;
            
        for(int col = 1; col <= m; col++)
        {
            if(isSafe(node, color, graph, n, col))
            {
                color[node] = col;
                if(solve(graph, n, m, node+1, color) == true)
                    return true;
                color[node] = 0;
            }
        }
        return false;
    }
    
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n,0);
        return solve(graph, n, m, 0, color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends