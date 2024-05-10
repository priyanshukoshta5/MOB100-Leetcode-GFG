class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int,int>>> maxH;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                maxH.push({double(arr[i]) / double(arr[j]), {arr[i], arr[j]}});
                if(maxH.size() > k)
                    maxH.pop();
            }
        }

        return {maxH.top().second.first, maxH.top().second.second};
    }
};