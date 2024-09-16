class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();

        vector<int> arr;
        for(string s: timePoints)
        {
            int hr = (int(s[0] - '0') * 10) + int(s[1] - '0');
            int mn = (int(s[3] - '0') * 10) + int(s[4] - '0');
            arr.push_back(hr * 60 + mn);
            cout<<hr<<" "<<mn<<endl;
        }

        sort(arr.begin(), arr.end());

        int ans = 24 * 60;
        for(int i = 1; i < n; i++)
            ans = min(ans, arr[i] - arr[i - 1]);
        
        ans = min(ans, 24 * 60 - (arr[n - 1] - arr[0]));

        return ans;
    }
};