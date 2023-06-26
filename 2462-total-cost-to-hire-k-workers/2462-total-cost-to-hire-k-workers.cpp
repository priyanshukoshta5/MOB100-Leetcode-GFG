class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long sum = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;
        int start = 0, last = n-1;

        int cnt = candidates;
        while(start <= last && cnt > 0)
        {
            if(start == last)
            {
                minH.push({costs[start], start});
                start++;
            }
            else
            {
                minH.push({costs[start], start});
                minH.push({costs[last], last});
                start++;
                last--;
            }
            cnt--;
        }

        cnt = k;
        while(cnt > 0)
        {
            auto it = minH.top();
            minH.pop();
            sum += it.first;
            if(start <= last)
            {
                if(it.second < start)
                {
                    minH.push({costs[start], start});
                    start++;
                }
                else
                {
                    minH.push({costs[last], last});
                    last--;
                }
            }
            cnt--;
        }
        
        return sum;
    }
};