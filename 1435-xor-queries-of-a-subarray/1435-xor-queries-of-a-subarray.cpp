class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> xors(n);
        xors[0] = arr[0];
        for(int i = 1; i < n; i++)
            xors[i] = arr[i] ^ xors[i - 1];
        
        vector<int> ans;
        for(auto q: queries)
        {
            int l = q[0];
            int r = q[1];
            if(l == 0)
                ans.push_back(xors[r]);
            else
                ans.push_back(xors[r] ^ xors[l - 1]);
        }

        return ans;
    }
};