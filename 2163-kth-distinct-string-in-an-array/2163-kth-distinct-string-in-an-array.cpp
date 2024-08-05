class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(int i = 0; i < arr.size(); i++)
        {
            if(mp.find(arr[i]) == mp.end())
                mp[arr[i]] = i;
            else
                mp[arr[i]] = -1;
        }

        map<int, string> distinct;
        for(auto x: mp)
        {
            if(x.second != -1)
                distinct[x.second] = x.first;
        }
        
        for(auto x: distinct)
        {
            k--;
            if(k == 0)
                return x.second;
        }

        return "";
    }
};