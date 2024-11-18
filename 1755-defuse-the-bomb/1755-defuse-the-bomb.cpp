class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();

        vector<int> ans(n, 0);

        if(k > 0)
        {
            int l = 1, r = 1;
            int sum = 0;
            int cnt = 0;
            while(cnt < k)
            {
                sum += code[r];
                r = (r + 1) % n;
                cnt++;
            }

            for(int i = 0; i < n; i++)
            {
                ans[i] = sum;
                sum -= code[l];
                sum += code[r];
                l = (l + 1) % n;
                r = (r + 1) % n;
            }
        }
        else if(k < 0)
        {
            int l = n - 1, r = n - 1;
            int sum = 0;
            int cnt = 0;
            while(cnt < abs(k))
            {
                sum += code[l];
                l = (l - 1) % n;
                cnt++;
            }

            for(int i = 0; i < n; i++)
            {
                ans[i] = sum;
                l = (l + 1) % n;
                sum -= code[l];
                sum += code[i];
                // r = (r + 1) % n;
            }
        }

        return ans;
    }
};