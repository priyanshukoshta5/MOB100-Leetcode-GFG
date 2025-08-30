class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        // checking row
        for(int i = 0; i < rows; i++){
            map<char, int> mp;
            for(auto x: board[i]){
                mp[x]++;
                if(x != '.' && mp[x] > 1)
                    return false;
            }
        }

        // checking cols
        for(int i = 0; i < cols; i++){
            map<char, int> mp;
            for(int j = 0; j < rows; j++){
                mp[board[j][i]]++;
                if(board[j][i]!= '.' && mp[board[j][i]] > 1)
                    return false;
            }
        }

        // checking boxes
        for(int i = 0; i < rows; i += 3){
            for(int j = 0; j < cols; j += 3){
                map<char, int> mp;
                for(int x = i; x < i + 3; x++){
                    for(int y = j; y < j + 3; y++){
                        mp[board[x][y]]++;
                        if(board[x][y] != '.' && mp[board[x][y]] > 1)
                            return false;
                    }
                }
            }
        }

        // passed all the checks
        return true;
    }
};