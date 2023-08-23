//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m ;
    }
    
    bool findWord(int r, int c, int ind, vector<vector<char>> &grid, string &word, int n, int m, int dr, int dc){
        // cout<<r<<" "<<c<<" "<<ind<<endl;
        if(ind == (word.size() - 1))
            return true;
        
        int newR = r + dr;
        int newC = c + dc;
        if(isValid(newR, newC, n, m) && grid[newR][newC] == word[ind + 1])
        {
            if(findWord(newR, newC, ind + 1, grid, word, n, m, dr, dc) == true)
                return true;
        }
        
        return false;
    }
    
public:
	vector<vector<int>> searchWord(vector<vector<char>>grid, string word){
	    int n = grid.size();
	    int m = grid[0].size();
	    
	    vector<vector<int>> ans;
	    
	    int dr[8] = {-1, -1, 0, +1, +1, +1, 0, -1};
	    int dc[8] = {0, +1, +1, +1, 0, -1, -1, -1};
	    
	    for(int i = 0; i < n; i++)
	    {
	        for(int j = 0; j < m; j++)
	        {
	            if(grid[i][j] == word[0])
	            {
    	            for(int d = 0; d < 8; d++)
    	            {
	                    if(findWord(i, j, 0, grid, word, n, m, dr[d], dc[d]) == true)
	                    {
	                        ans.push_back({i, j});
	                        break;
	                    }
    	            }
	            }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends