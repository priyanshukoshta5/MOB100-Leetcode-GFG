class Solution {
public:
    bool isPathCrossing(string path) {
        map<char, pair<int,int>> movements;
        movements['N'] = {-1, 0};
        movements['S'] = {+1, 0};
        movements['E'] = {0, +1};
        movements['W'] = {0, -1};

        pair<int,int> curPos = {0,0};
        set<pair<int,int>> visited;
        visited.insert(curPos);

        for(char ch: path)
        {
            pair<int,int> move = movements[ch];
            curPos.first += move.first;
            curPos.second += move.second;

            if(visited.find(curPos) != visited.end())
                return true;
            else
                visited.insert(curPos);
        }

        return false;
    }
};