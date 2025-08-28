class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<int> arr;
        int i, j, x, y, z;

        // moving on top row, left to right
        j = 1;
        while(j < cols){
            arr.clear();

            x = 0;
            y = j;
            while(x < rows && y < cols){
                arr.push_back(grid[x][y]);
                x++;
                y++;
            }

            sort(arr.begin(), arr.end());
            // for(auto val: arr)
            //     cout<<val<<" ";
            // cout<<endl;

            x = 0;
            y = j;
            z = 0;
            while(x < rows && y < cols){
                grid[x][y] = arr[z];
                x++;
                y++;
                z++;
            }

            j++;
        }

        // moving on leftmost col, top to bottom
        i = 0;
        while(i < rows){
            arr.clear();

            x = i;
            y = 0;
            while(x < rows && y < cols){
                arr.push_back(grid[x][y]);
                x++;
                y++;
            }

            sort(arr.begin(), arr.end(), greater<int> ());
            // for(auto val: arr)
            //     cout<<val<<" ";
            // cout<<endl;

            x = i;
            y = 0;
            z = 0;
            while(x < rows && y < cols){
                grid[x][y] = arr[z];
                x++;
                y++;
                z++;
            }

            i++;
        }

        return grid;
    }
};