class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<long long> arr;
        long long i = 0;
        long long val = 0;
        while(val <= c)
        {
            arr.push_back(val);
            i++;
            val = pow(i, 2);
        }

        int low = 0;
        int n = arr.size();
        while(low < n)
        {
            // cout<<arr[low]<<" "<<c-arr[low]<<endl;
            if(binary_search(arr.begin(), arr.end(), c - arr[low]))
                return true;
            low++;
        }

        return false;
    }
};