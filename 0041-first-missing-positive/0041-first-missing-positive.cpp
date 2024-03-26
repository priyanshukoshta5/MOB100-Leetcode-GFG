class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        for(int i: nums)
        {
            if(i > 0)
                st.insert(i);
        }

        int num = 1;
        for(int i: st)
        {
            if(i != num)
                break;
            num++;
        }
        
        return num;
    }
};