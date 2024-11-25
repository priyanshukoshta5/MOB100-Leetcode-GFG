class Solution {
private:
    bool check(vector<vector<int>>& arr, vector<vector<int>>& solved){
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(arr[i][j] != solved[i][j])
                    return false;
            }
        }
        return true;
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> solved = {{1, 2, 3}, {4, 5, 0}};
        queue<vector<vector<int>>> q;
        set<vector<vector<int>>> st;
        st.insert(board);
        q.push(board);
        int move = 0;
        while(move < 50)
        {
            int size = q.size();
            while(size--)
            {
                vector<vector<int>> arr = q.front();
                q.pop();

                // for(auto i: arr)
                // {
                //     for(int j: i)
                //         cout<<j<<" ";
                // }
                // cout<<endl;

                if(check(arr, solved))
                    return move;

                int x = 0, y = 0;
                for(int i = 0; i < 2; i++)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        if(arr[i][j] == 0)
                        {
                            x = i;
                            y = j;
                            break;
                        }
                    }
                }
                
                if((x - 1) >= 0)
                {
                    swap(arr[x - 1][y], arr[x][y]);
                    if(st.find(arr) == st.end())
                        q.push(arr);
                    st.insert(arr);
                    swap(arr[x - 1][y], arr[x][y]);
                }
                if((x + 1) < 2)
                {
                    swap(arr[x + 1][y], arr[x][y]);
                    if(st.find(arr) == st.end())
                        q.push(arr);
                    st.insert(arr);
                    swap(arr[x + 1][y], arr[x][y]);
                }
                if((y - 1) >= 0)
                {
                    swap(arr[x][y - 1], arr[x][y]);
                    if(st.find(arr) == st.end())
                        q.push(arr);
                    st.insert(arr);
                    swap(arr[x][y - 1], arr[x][y]);
                }
                if((y + 1) < 3)
                {
                    swap(arr[x][y + 1], arr[x][y]);
                    if(st.find(arr) == st.end())
                        q.push(arr);
                    st.insert(arr);
                    swap(arr[x][y + 1], arr[x][y]);
                }
            }

            move++;
        }

        return -1;
    }
};