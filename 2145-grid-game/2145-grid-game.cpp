// class Solution {
// public:
//     long long gridGame(vector<vector<int>>& grid) {
//         int n = grid[0].size();

//         vector<vector<int>> pre(2, vector<int> (n, 0));

//         pre[0][0] = grid[0][0];     // taking forward
//         for(int i = 1; i < n; i++)
//             pre[0][i] = grid[0][i] + pre[0][i - 1];

//         pre[1][n - 1] = grid[1][n - 1];     // taking backward
//         for(int i = n - 2; i >= 0; i--)
//             pre[1][i] = grid[1][i] + pre[0][i + 1];

//         int robot1Max = max(pre[0][0] + grid[1][n - 1], pre[0][0] + pre[1][0]);
//         for(int i = 0; i < n; i++)
//         {
//             // case 1 for Robot1, move right
//             // already taken maximum 

//             // case 2 for Robot1, move down
//             robot1Max = max(robot1Max, pre[0][i] + pre[1][i]);
//         }

//         int ans = 0;
//         if(robot1Max == pre[0][0])
//             ans = max(ans, pre[0][0]);

//         for(int i = 0; i < n; i++)
//         {
//             if(robot1Max == pre[0][i] + pre[1][i])
//             {

//             }
//         }

//         return ans;
//     }
// };

// ~Editorial

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL),
                  secondRowSum = 0;
        long long minimumSum = LONG_LONG_MAX;
        for (int turnIndex = 0; turnIndex < grid[0].size(); ++turnIndex) {
            firstRowSum -= grid[0][turnIndex];
            // Find the minimum maximum value out of firstRowSum and
            // secondRowSum.
            minimumSum = min(minimumSum, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][turnIndex];
        }
        return minimumSum;
    }
};