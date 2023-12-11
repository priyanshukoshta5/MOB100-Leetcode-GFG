class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> freq;
        int n = arr.size();
        int _25 = n / 4;
        for(int i: arr)
        {
            freq[i]++;
            if(freq[i] > _25)
                return i;
        }
        return -1;
    }
};