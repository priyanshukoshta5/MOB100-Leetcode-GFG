class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i: nums)
        {
            if(i > 0)
                st.insert(i);
        }

        int num = 1;
        while(true)
        {
            if(st.find(num) == st.end())
                break;
            num++;
        }
        
        return num;
    }
};