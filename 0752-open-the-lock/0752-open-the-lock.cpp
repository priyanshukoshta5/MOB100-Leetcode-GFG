class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> vis(deadends.begin(), deadends.end());
        if(vis.find("0000") != vis.end())
            return -1;

        queue<pair<int, string>> q;
        q.push({0, "0000"});
        while(!q.empty())
        {
            auto it = q.front(); 
            q.pop();
            int d = it.first;
            string cur = it.second, next;
            // cout<<d<<" "<<cur<<endl;

            if(cur == target)
                return d;

            for(int i = 0; i < 4; i++)
            {
                // increment 'ith'
                next = cur;
                next[i] = ('0' + ((next[i] - '0') + 1) % 10);
                if(vis.find(next) == vis.end())
                {
                    q.push({d + 1, next});
                    vis.insert(next);
                }

                // decrement 'ith'
                next = cur;
                if(next[i] == '0') 
                    next[i] = '9';
                else 
                    next[i] = (next[i] - 1);
                if(vis.find(next) == vis.end())
                {
                    q.push({d + 1, next});
                    vis.insert(next);
                }
            }
        }

        return -1;
    }
};