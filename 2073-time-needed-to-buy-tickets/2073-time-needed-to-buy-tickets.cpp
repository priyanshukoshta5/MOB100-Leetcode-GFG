class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
            q.push({tickets[i], i});
        
        int tm = 0;
        while(true)
        {
            auto it = q.front(); q.pop();
            it.first--;
            tm++;
            if(it.first != 0)
                q.push(it);
            else if(it.second == k)
                break;
        }

        return tm;
    }
};