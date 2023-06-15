class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> arr;
        for(int i : nums)
        {
            int ind = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
            if(ind == arr.size())
                arr.push_back(i);
            else
                arr[ind] = i;
        }
        return arr.size();
    }
};