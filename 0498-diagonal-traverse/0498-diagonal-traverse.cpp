class Solution {
private:
    bool isValid(int i, int j, int rows, int cols){
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }

public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> traversal;
        int i = 0, j = 0;
        int dir = 1;
        while(true){
            // cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;

            traversal.push_back(mat[i][j]);
            if(i == rows - 1 && j == cols - 1)
                break;

            if(isValid(i - dir, j + dir, rows, cols)){
                i = i - dir;
                j = j + dir;
            }
            else if(dir == 1){
                if(isValid(i, j + 1, rows, cols)){      // shift to right
                    j = j + 1;
                }
                else if(isValid(i + 1, j, rows, cols)){ // shift to down
                    i = i + 1;
                }
                dir = -1;
            }
            else if(dir == -1){
                if(isValid(i + 1, j, rows, cols)){      // shift to down 
                    i = i + 1;
                }
                else if(isValid(i, j + 1, rows, cols)){ // shift to right
                    j = j + 1;
                }
                dir = 1;
            }
        }

        return traversal;
    }
};