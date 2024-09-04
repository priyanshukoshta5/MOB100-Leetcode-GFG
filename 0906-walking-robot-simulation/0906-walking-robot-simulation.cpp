class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, +1, 0, -1};     // up right down left
        int dy[4] = {+1, 0, -1, 0};     // up right down left
        int move = 0;
        int x = 0, y = 0;
        int ans = 0;
        set<pair<int,int>> obs;
        for(auto o: obstacles)
            obs.insert({o[0], o[1]});
        for(int c: commands)
        {
            if(c == -1)
            {
                if(move == 3)
                    move = 0;
                else
                    move = (move + 1) % 4;
            }
            else if(c == -2)
            {
                if(move == 0)
                    move = 3;
                else
                    move = (move - 1) % 4;
            }
            else
            {
                int k = c;
                while(k--)
                {
                    if(obs.find({x + dx[move], y + dy[move]}) == obs.end())
                    {
                        x = x + dx[move];
                        y = y + dy[move];
                        int euc = pow(x, 2) + pow(y, 2);
                        ans = max(ans, euc);
                    }
                    else
                        break;
                }
            }
        }
        return ans;
    }
};