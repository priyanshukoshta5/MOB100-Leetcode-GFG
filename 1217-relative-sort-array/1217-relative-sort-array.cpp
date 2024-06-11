class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001, 0);
        for(int i: arr1)
            freq[i]++;
        
        vector<int> ans;
        for(int i: arr2)
        {
            for(int j = 0; j < freq[i]; j++)
                ans.push_back(i);
            freq[i] = 0;
        }

        for(int i = 0; i <= 1000; i++)
        {
            for(int j = 0; j < freq[i]; j++)
                ans.push_back(i);
        }

        return ans;
    }
};