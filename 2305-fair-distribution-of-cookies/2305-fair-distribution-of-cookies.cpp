class Solution {
private:
    int solve(int ind, vector<int> &childrens, vector<int> &cookies){
        if(ind < 0)
        {
            int ans = INT_MIN;
            for(int i: childrens)
            {
                if(i == 0)  ans = INT_MAX;
                else ans = max(ans, i);
            }
            return ans;
        }

        int res = INT_MAX;
        for(int c = 0; c < childrens.size(); c++)
        {
            childrens[c] += cookies[ind];
            res = min(res, solve(ind-1, childrens, cookies));
            childrens[c] -= cookies[ind];
        }

        return res;
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int> childrens(k, 0);
        return solve(n-1, childrens, cookies);
    }
};