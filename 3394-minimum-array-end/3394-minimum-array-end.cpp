class Solution {
private:
    vector<int> decToBin(int n){
        vector<int> arr(32, 0);
        for(int i = 0; i < 32; i++)
            arr[i] = (n >> i) & 1;
        return arr;
    }
    
public:
    long long minEnd(int n, int x) {
        vector<int> a = decToBin(x);
        vector<int> b = decToBin(n - 1);
        // for(int i = 0; i < 32; i++)
        //     cout<<a[i];
        // cout<<endl;
        // for(int i = 0; i < 32; i++)
        //     cout<<b[i];
        // cout<<endl;
        
        int i = 0, j = 0;
        while(i < 32)
        {
            if(a[i] == 0)
            {
                a[i] = b[j];
                i++;
                j++;
            }
            else
                i++;
        }
        while(j < 32)
        {
            a.push_back(b[j]);
            j++;
        }
        
        // for(auto z: a) cout<<z;
        // cout<<endl;
        
        long long ans = 0;
        long long exp = 1;
        for(int z: a)
        {
            if(z == 1)
            {
                ans += exp;
            }
            exp = exp * 2;
        }
        
        return ans;
    }
};