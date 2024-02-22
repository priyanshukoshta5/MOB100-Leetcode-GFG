class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1)
            return 1;

        unordered_map<int, int> trustFreq;
        for(auto i: trust)
            trustFreq[i[1]]++;
        
        bool exists = true;
        int judge = -1;
        for(auto x: trustFreq)
        {
            if(x.second == (n - 1))
            {
                if(exists == false)
                    return -1;
                exists = false;
                judge = x.first;
            }
        }

        // checking that judge not trust anyone
        for(auto i: trust)
            if(i[0] == judge)
                return -1;

        return judge;
    }
};