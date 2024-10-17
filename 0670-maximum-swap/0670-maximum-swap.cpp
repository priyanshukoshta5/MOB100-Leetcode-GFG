class Solution {
public:
    int maximumSwap(int num) {
        int ans = num;
        string val = to_string(num);
        for(int i = 0; i < val.length(); i++)
        {
            for(int j = i + 1; j < val.length(); j++)
            {
                swap(val[i], val[j]);
                ans = max(ans, stoi(val));
                swap(val[i], val[j]);
            }
        }
        return ans;
    }
};