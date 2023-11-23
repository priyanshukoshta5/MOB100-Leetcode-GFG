// Brute Force

class Solution {
private:
    bool isArithmetic(vector<int> &nums, int l, int r){
        if((r - l) <= 1)
            return true;
        
        vector<int> arr(nums.begin() + l, nums.begin() + r + 1);
        sort(arr.begin(), arr.end());
        
        int diff = arr[1] - arr[0];
        for(int i = 1; i < arr.size(); i++)
        {
            if((arr[i] - arr[i - 1]) != diff)
                return false;
        }
        
        return true;
    }

public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0; i < l.size(); i++)
            ans.push_back(isArithmetic(nums, l[i], r[i]));
        return ans;
    }
};