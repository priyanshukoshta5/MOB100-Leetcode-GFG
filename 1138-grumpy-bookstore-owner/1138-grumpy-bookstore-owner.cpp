class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        int total = 0;
        for(int i = 0; i < n; i++)
        {
            if(grumpy[i] == 0)
                total += customers[i];
        }
        
        int ans = 0;
        int i = 0;
        int extra = 0;
        for(int j = 0; j < customers.size(); j++)
        {
            if(grumpy[j] == 1)
                extra += customers[j];
            if(j - i + 1 == minutes)
            {
                ans = max(ans, total + extra);
                if(grumpy[i] == 1)
                    extra -= customers[i];
                i++;
            }
        }

        return ans;
    }
};