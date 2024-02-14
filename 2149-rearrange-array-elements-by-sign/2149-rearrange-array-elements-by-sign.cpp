class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(auto i: nums)
        {
            if(i < 0)   
                neg.push_back(i);
            else    
                pos.push_back(i);
        }

        for(int i = 0; i < nums.size(); i += 2)
        {
            nums[i] = pos[i / 2];
            nums[i + 1] = neg[i / 2];
        }

        return nums;
    }
};