class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> st(arr.begin(), arr.end());
        int zero = count(arr.begin(), arr.end(), 0);
        if(zero > 1)
            return true;
        for(int i: arr)
        {
            if(i != 0 && st.find(i * 2) != st.end())
                return true;
        }
        return false;
    }
};