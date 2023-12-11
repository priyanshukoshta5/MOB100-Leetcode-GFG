// ~ Editorial, amazing

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> freq;
        int n = arr.size();
        int _25 = n / 4;
        vector<int> possibilities = {arr[_25], arr[n / 2], arr[3 * n / 4]};
        
        for(int i: possibilities)
        {
            int left = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
            int right = upper_bound(arr.begin(), arr.end(), i) - arr.begin();
            if((right - left) > _25)
                return i;
        }
        
        return -1;
    }
};