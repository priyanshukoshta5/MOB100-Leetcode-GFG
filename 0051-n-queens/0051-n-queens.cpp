class Solution {
private:
    bool diaCheck(vector<string>& board, int r, int c){
        int i, j;

        i=r, j=c;
        i--; j--;
        while(i>=0 && j>=0){
            if(board[i][j] == 'Q') return false;
            i--; j--;
        }

        i=r, j=c;
        i--; j++;
        while(i>=0 && j<board.size()){
            if(board[i][j] == 'Q') return false;
            i--; j++;
        }

        return true;
    }
    bool axisCheck(vector<string>& board, int r, int c){
        for(int i=0; i<r; i++)
            if(board[i][c] == 'Q')
                return false;
        return true;
    }

    void queens(int row, int n, vector<string>& board, vector<vector<string>>& ans){
        if(row == n)
        {
            ans.push_back(board);
            return;
        }

        for(int col=0; col<n; col++)
        {
            if(diaCheck(board, row, col) && axisCheck(board, row, col))
            {
                board[row][col] = 'Q';
                queens(row+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        string s; 
        for(int i=0; i<n; i++)
            s.push_back('.');

        vector<string> board(n, s);
        vector<vector<string>> ans;
        
        queens(0, n, board, ans);

        return ans;
    }
};