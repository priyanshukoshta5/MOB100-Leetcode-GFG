class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        
        vector<int> order;
        queue<int> q;
        for(int i = 0; i < n; i++)
            q.push(i);
        
        while(!q.empty())
        {
            int top = q.front();    q.pop();
            order.push_back(top);
            if(q.size() > 1)
            {
                q.push(q.front());
                q.pop();
            }
        }

        sort(deck.begin(), deck.end());

        vector<int> ans(n);
        for(int i = 0; i < n; i++)
            ans[order[i]] = deck[i];

        return ans;
    }
};