class Solution {
private:
    int rowPresent[9][9];
    int colPresent[9][9];
    int boxPresent[3][3][9];
    int flag = false;

    void solve(int i, int j, vector<vector<char>> &board){
        if(flag)
            return;
        if(i == 9){
            // for(int x = 0; x < 9; x++){
            //     for(int y = 0; y < 9; y++){
            //         cout<<board[x][y]<<" ";
            //     }
            //     cout<<endl;
            // }
            flag = true;
            return;
        }

        int nI, nJ;
        if(j + 1 < 9){
            nI = i;
            nJ = j + 1;
        }
        else{
            nI = i + 1;
            nJ = 0;
        }

        if(board[i][j] == '.'){
            for(int c = 1; c <= 9; c++){
                if(!flag && !rowPresent[i][c - 1] && !colPresent[j][c - 1] && !boxPresent[i / 3][j / 3][c - 1]){
                    board[i][j] = ('0' + c);
                    rowPresent[i][c - 1] = true;
                    colPresent[j][c - 1] = true;
                    boxPresent[i / 3][j / 3][c - 1] = true;
                    solve(nI, nJ, board);
                    if(flag) return;
                    rowPresent[i][c - 1] = false;
                    colPresent[j][c - 1] = false;
                    boxPresent[i / 3][j / 3][c - 1] = false;
                    board[i][j] = '.';
                }
            }
        }
        else{
            solve(nI, nJ, board);
        }

        return;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        flag = false;

        // marking existing values in the board
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                rowPresent[i][board[i][j] - '1'] = true;
                colPresent[j][board[i][j] - '1'] = true;
                boxPresent[i / 3][j / 3][board[i][j] - '1'] = true;
            }
        }

        solve(0, 0, board);
    }
};