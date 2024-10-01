class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> temp;
        for(int i: arr)
        {
            temp[(i % k + k) % k]++;
            // cout<<i<<" "<<(i % k + k) % k<<endl;
        }

        for(auto i: arr)
        {
            int rem = (i % k + k) % k;
            if(rem == 0)
            {
                if(temp[rem] % 2 == 1) 
                    return false;
            }
            else if(temp[rem] != temp[k - rem])
                return false;

        }

        return true;
    }
};