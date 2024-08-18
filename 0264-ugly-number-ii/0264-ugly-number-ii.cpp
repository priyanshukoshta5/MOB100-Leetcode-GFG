class Solution {
public:
    int nthUglyNumber(int n) {
        int ans = 1;
        set<int> st;
        st.insert(1);
        while(n > 0)
        {
            int val = *st.begin();
            st.erase(val);
            ans = val;
            if((1LL * val * 2) <= INT_MAX)
                st.insert(val * 2);
            if((1LL * val * 3) <= INT_MAX)
                st.insert(val * 3);
            if((1LL * val * 5) <= INT_MAX)
                st.insert(val * 5);
            n--;
        }
        return ans;
    }
};