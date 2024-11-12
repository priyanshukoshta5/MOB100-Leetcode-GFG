class Solution {
private:
    int myBinSearch(vector<pair<int, int>> &arr, int p){
        int l = 0, r = arr.size() - 1;
        while(l <= r)
        {
            int m = l + (r - l) / 2;
            if(arr[m].first <= p)
                l = m + 1;
            else
                r = m - 1;
        }
        return l - 1;
    }

public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());
        vector<pair<int, int>> arr;
        int maxB = 0;
        for(int i = 0; i < items.size(); i++)
        {
            maxB = max(maxB, items[i][1]);
            arr.push_back({items[i][0], maxB});
        }
        // for(auto x: arr)
        //     cout<<x.first<<" "<<x.second<<endl;

        vector<int> ans;
        for(int q: queries)
        {
            if(q < items[0][0])
                ans.push_back(0);
            else
                ans.push_back(arr[myBinSearch(arr, q)].second);
        }

        return ans;
    }
};