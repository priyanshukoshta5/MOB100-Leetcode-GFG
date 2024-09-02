class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for(int i: chalk)
            total = total + i;
        
        if(k >= total)
            k = k % total;
        
        for(int i = 0; i < chalk.size(); i++)
        {
            if(chalk[i] > k)
                return i;
            k = k - chalk[i];
        }

        return 0;
    }
};