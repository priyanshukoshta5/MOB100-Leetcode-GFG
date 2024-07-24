class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map<int, vector<int>> mp;
        for(int i: nums)
        {
            int code = 0;
            long temp = 1;
            int num = i;
            if(num == 0)
                code = mapping[num];
            while(num > 0)
            {
                code += (mapping[num % 10] * temp);
                num = num / 10;
                temp = temp * 10;
            }
            mp[code].push_back(i);
        }

        vector<int> ans;
        for(auto x: mp)
        {
            // cout<<x.first<<" -> ";
            for(int i: x.second)
            {
                // cout<<i<<" ";
                ans.push_back(i);
            }
            // cout<<endl;
        }
        return ans;
    }
};