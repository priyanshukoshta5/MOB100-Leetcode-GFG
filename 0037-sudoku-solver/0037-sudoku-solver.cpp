class Solution {
    
public:
    int rowFill[9][9] = {0};
    int colFill[9][9] = {0};
    int box[3][3][9] = {0};

    bool solve(vector<vector<char>>& board, int row, int col){
        if(row == 9)
            return true;

        int nextrow, nextcol;
        if(col == 8)
            nextrow=row+1, nextcol=0;
        else
            nextrow=row, nextcol=col+1;

        bool flag = false;

        if(board[row][col] != '.')
            flag = solve(board, nextrow, nextcol);
        else
        {
            for(int num=0; num<9; num++)
            {
                if(rowFill[num][row]==0  && colFill[num][col]==0 && box[row/3][col/3][num]==0)
                {
                    board[row][col] = char(num+'1');
                    rowFill[num][row] = 1;
                    colFill[num][col] = 1;
                    box[row/3][col/3][num] = 1;

                    flag = solve(board, nextrow, nextcol);
                    if(flag == true)
                        return true;
                    
                    board[row][col] = '.';
                    rowFill[num][row] = 0;
                    colFill[num][col] = 0;
                    box[row/3][col/3][num] = 0;
                }
            }
        }

        return flag;
    }    

    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.')
                {
                    rowFill[board[i][j]-'1'][i] = 1;
                    colFill[board[i][j]-'1'][j] = 1;
                    box[i/3][j/3][board[i][j]-'1'] = 1;
                }
            }
        }
        solve(board, 0, 0);
    }
};