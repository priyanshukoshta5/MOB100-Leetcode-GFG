// class Solution {
// public:
//     vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
//         int m = box.size();
//         int n = box[0].size();

//         vector<vector<char>> rotated(m, vector<char> (n));
//         for(int i = 0; i < n; i++)
//         {
//             for(int j = 0; j < m; j++)
//                 rotated[i][j] = box[j][i];
//         }

//         for(int col = 0; col < m; col++)
//         {
//             int j = n - 1;
//             for(int row = n - 1; row >= 0; row--)
//             {
//                 if(rotated[row][col] == '#')
//                 {
//                     swap(rotated[row][col], rotated[j][col]);
//                     while(j < )
//                 }
//                 else if(rotated[row][col] == '*')
//                 else if(rotated[row][col] == '.')
//             }
//         }
//     }
// };

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m));

        // Create the transpose of the input grid in `result`
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = box[j][i];
            }
        }

        // Reverse each row in the transpose grid to complete the 90° rotation
        for (int i = 0; i < n; i++) {
            reverse(result[i].begin(), result[i].end());
        }

        // Apply gravity to let stones fall to the lowest possible empty cell in
        // each column
        for (int j = 0; j < m; j++) {
            // Process each cell in column `j` from bottom to top
            for (int i = n - 1; i >= 0; i--) {
                if (result[i][j] == '.') {  // Found an empty cell; check if a
                                            // stone can fall into it
                    int nextRowWithStone = -1;

                    // Look for a stone directly above the empty cell
                    // `result[i][j]`
                    for (int k = i - 1; k >= 0; k--) {
                        if (result[k][j] == '*')
                            break;  // Obstacle blocks any stones above
                        if (result[k][j] ==
                            '#') {  // Stone found with no obstacles in between
                            nextRowWithStone = k;
                            break;
                        }
                    }

                    // If a stone was found above, let it fall into the empty
                    // cell `result[i][j]`
                    if (nextRowWithStone != -1) {
                        result[nextRowWithStone][j] = '.';
                        result[i][j] = '#';
                    }
                }
            }
        }
        return result;
    }
};