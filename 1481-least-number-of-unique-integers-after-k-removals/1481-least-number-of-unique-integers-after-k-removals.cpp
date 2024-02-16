class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        for(int i: arr)
            freq[i]++;
        
        vector<int> freqArr;
        for(auto x: freq)
            freqArr.push_back(x.second);

        sort(freqArr.begin(), freqArr.end());

        int cnt = freqArr.size();
        for(int i: freqArr)
        {
            if(k >= i)
            {
                k -= i;
                cnt--;
            }
        }

        return cnt;
    }
};