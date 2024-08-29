// class Solution {
// private:
//     int dfs(int i, vector<int> &vis, vector<vector<int>> &adjRow, vector<vector<int>> &adjCol, vector<vector<int>>& stones){
//         vis[i] = 1;

//         int cnt = 0;

//         for(int j = 0; j < adjRow[stones[i][0]].size(); i++)
//         {
//             if(vis[adjRow[stones[i][0]][j]] == 0)
//             {
//                 cnt += dfs(adjRow[stones[i][0]][j], vis, adjRow, adjCol, stones);
//             }
//         }

//         for(int j = 0; j < adjCol[stones[i][1]].size(); i++)
//         {
//             if(vis[adjCol[stones[i][1]][j]] == 0)
//             {
//                 cnt += dfs(adjCol[stones[i][1]][j], vis, adjRow, adjCol, stones);
//             }
//         }

//         return 1 + cnt;
//     }

// public:
//     int removeStones(vector<vector<int>>& stones) {
//         int nRow = 0;
//         int nCol = 0;
//         for(auto i: stones)
//         {
//             nRow = max(nRow, i[0] + 1);
//             nCol = max(nCol, i[1] + 1);
//         }

//         vector<vector<int>> adjRow(nRow), adjCol(nCol);
//         for(int i = 0; i < stones.size(); i++)
//         {
//             adjRow[stones[i][0]].push_back(i);
//             adjCol[stones[i][1]].push_back(i);
//         }

//         int ans = 0;
//         vector<int> vis(stones.size(), 0);
//         for(int i = 0; i < stones.size(); i++)
//         {
//             if(vis[i] == 0)
//             {
//                 ans = max(ans, dfs(i, vis, adjRow, adjCol, stones));
//             }
//         }

//         return ans;
//     }
// };



// ~Editorial

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        // Adjacency list to store graph connections
        vector<vector<int>> adjacencyList(n);

        // Build the graph: Connect stones that share the same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }

        int numOfConnectedComponents = 0;
        vector<bool> visited(n, false);

        // Traverse all stones using DFS to count connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                depthFirstSearch(adjacencyList, visited, i);
                numOfConnectedComponents++;
            }
        }

        // Maximum stones that can be removed is total stones minus number of
        // connected components
        return n - numOfConnectedComponents;
    }

private:
    // DFS to visit all stones in a connected component
    void depthFirstSearch(vector<vector<int>>& adjacencyList,
                          vector<bool>& visited, int stone) {
        visited[stone] = true;

        for (int neighbor : adjacencyList[stone]) {
            if (!visited[neighbor]) {
                depthFirstSearch(adjacencyList, visited, neighbor);
            }
        }
    }
};