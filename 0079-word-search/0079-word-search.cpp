class Solution {
private:
    int dr[4] = {0, -1, 0, +1};
    int dc[4] = {-1, 0, +1, 0};

    bool isValid(int r, int c, int n, int m){
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    void solve(vector<vector<char>>& board, string word, vector<vector<bool>>& marked, int i, int j, int p, bool& ans)
    {
        if(p == word.length() - 1 && board[i][j] == word[p])
        {
            ans = true;
            return;
        }

        if(board[i][j] == word[p])
        {
            marked[i][j] = true;

            for(int t = 0; t < 4; t++)
            {
                int newI = dr[t] + i;
                int newJ = dc[t] + j;
                if(isValid(newI, newJ, board.size(), board[0].size()) && marked[newI][newJ] == false)
                    solve(board, word, marked, newI, newJ, p+1, ans);
            }
            
            marked[i][j] = false;
        }

        return;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> marked(n, vector<bool> (m, false));
        bool ans = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(ans == false)
                    solve(board, word, marked, i, j, 0, ans);
                else
                    break;
            }
            if(ans == true)
                break;
        }

        return ans;
    }
};