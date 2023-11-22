class Solution {
public:
    // BFS , got idea by Editorial, and coding myself

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;    // answer array

        queue<pair<int, int>> q;    // queue {row, col} for bfs
        q.push({0, 0});  // pushing starting cell

        // will travel diagonal wise
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;

            // pushing elements in the answer
            ans.push_back(nums[x][y]);

            // pushing initial bottom element, only for first element in a diagonal
            if(y == 0 && (x + 1) < nums.size())
                q.push({x + 1, 0});

            // pushing element of next diagonal in the bfs queue
            if((y + 1) < nums[x].size())
                q.push({x, y + 1});
            
        }

        return ans;     // returning answer(traversal)
    }
};