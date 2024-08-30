//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private:
    bool colCheck(int c, int size, vector<vector<bool>> &board){
        for(int i = 0; i < size; i++)
        {
            if(board[i][c] == true)
                return false;
        }
        return true;
    }
    
    bool diaCheck(int r, int c, int size, vector<vector<bool>> &board){
        int i, j;
        
        i = r; j = c;
        while(i < size && j >= 0)
        {
            if(board[i][j] == true)
                return false;
            i++;
            j--;
        }
        
        i = r; j = c;
        while(i < size && j < size)
        {
            if(board[i][j] == true)
                return false;
            i++;
            j++;
        }
        
        return true;
    }

    void dfs(int n, int size, vector<vector<bool>> &board, vector<int> &order, vector<vector<int>> &ans){
        if(n == -1)
        {
            ans.push_back(order);
            return;
        }
        
        for(int i = 0; i < size; i++)
        {
            if(colCheck(i, size, board) && diaCheck(n, i, size, board))
            {
                board[n][i] = true;
                order.push_back(i + 1);
                dfs(n - 1, size, board, order, ans);
                order.pop_back();
                board[n][i] = false;
            }
        }
        
        return;
    }
    
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<vector<bool>> board(n, vector<bool> (n, false));
        vector<int> order;
        dfs(n - 1, n, board, order, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends