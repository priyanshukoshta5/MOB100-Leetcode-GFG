//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, +1, 0, -1};

    bool isSafe(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m ;
    }

    void searchWord(int n, int m, vector<vector<char>>& board, int r, int c, string& word, int k, vector<vector<int>>& visited, bool &cnt){
        if(k == word.length())
        {
            cnt = true;
            return;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int newR = r + dr[i];
            int newC = c + dc[i];
            if(isSafe(newR, newC, n, m) == true && visited[newR][newC] == 0 && board[newR][newC] == word[k])
            {
                visited[newR][newC] = 1;
                searchWord(n, m, board, newR, newC, word, k+1, visited, cnt);
                visited[newR][newC] = 0;
            }
        }
    }

public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> visited(n, vector<int> (m,0));
        
        bool cnt = false;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                if(board[r][c] == word[0])
                {
                    visited[r][c] = 1;
                    searchWord(n, m, board, r, c, word, 1, visited, cnt);
                    visited[r][c] = 0;
                    if(cnt == true)
                        return true;
                }
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends