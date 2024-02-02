class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i = 1; i <= 8; i++)
        {
            long num = i;
            for(int j = i + 1; j <= 9; j++)
            {
                int prev = num % 10;
                if(prev == 9)
                    break;
                
                num = num * 10;
                num = num + (prev + 1);

                if(num >= low && num <= high)
                    ans.push_back(num);
            }
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};