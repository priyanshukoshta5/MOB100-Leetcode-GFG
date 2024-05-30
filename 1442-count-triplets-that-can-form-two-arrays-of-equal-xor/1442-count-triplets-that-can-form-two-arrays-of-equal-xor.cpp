class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();

        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int a = arr[i];
            for(int j = i + 1; j < n; j++)
            {
                int b = arr[j];
                if(a == b)
                {
                    ans++;
                    // cout<<i<<" "<<j<<" "<<j<<endl;
                }
                for(int k = j + 1; k < n; k++)
                {
                    b = b ^ arr[k];
                    if(a == b)
                    {
                        ans++;
                        // cout<<i<<" "<<j<<" "<<k<<endl;
                    }
                }
                a = a ^ arr[j];
            }
        }

        return ans;
    }
};