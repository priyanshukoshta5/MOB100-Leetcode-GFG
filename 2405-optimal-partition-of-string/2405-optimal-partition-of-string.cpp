class Solution {
public:
    int partitionString(string s) {
        vector<int> index(26,-1);
        int partitions = 0;
        int i=-1, j=0;
        while(j < s.length())
        {
            if(index[s[j]-'a'] >= i)
            {
                partitions++;
                i = j;
            }
            index[s[j]-'a'] = j;
            j++;
        }
        return partitions;
    }
};