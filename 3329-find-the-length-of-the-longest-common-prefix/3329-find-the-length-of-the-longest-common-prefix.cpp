class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> st;
        for(int i: arr1)
        {
            string num = to_string(i);
            for(int j = 0; j < num.length(); j++)
                st.insert(num.substr(0, j + 1));
        }

        int ans = 0;
        for(int i: arr2)
        {
            string num = to_string(i);
            for(int j = 0; j < num.length(); j++)
            {
                if(st.find(num.substr(0, j + 1)) != st.end())
                    ans = max(ans, j + 1);
            }
        }

        return ans;
    }
};