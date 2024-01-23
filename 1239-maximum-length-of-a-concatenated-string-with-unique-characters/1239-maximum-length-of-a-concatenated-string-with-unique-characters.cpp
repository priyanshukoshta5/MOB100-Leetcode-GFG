class Solution {
private:
    int ans = 0;
    void findMaxLength(int ind, vector<string> &arr, vector<int> &freq){
        bool flag = false;
        int cnt = 0;
        for(int i: freq)
        {
            cnt += i;
            flag = flag | (i >= 2);
        }
        if(flag == false)
            ans = max(ans, cnt);

        if(ind == arr.size())
            return;
        
        // skip string at 'ind'
        findMaxLength(ind + 1, arr, freq);

        // take string at 'ind'
        for(char ch: arr[ind])
            freq[ch - 'a']++;
        findMaxLength(ind + 1, arr, freq);
        for(char ch: arr[ind])
            freq[ch - 'a']--;

        return;
    }

public:
    int maxLength(vector<string>& arr) {
        vector<int> freq(26, 0);
        findMaxLength(0, arr, freq);
        return ans;
    }
};