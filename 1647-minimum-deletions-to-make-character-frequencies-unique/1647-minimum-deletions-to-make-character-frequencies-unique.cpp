class Solution {
public:
    int minDeletions(string s) {\
        // finding the frequency of each characters
        vector<int> freq(26, 0);
        for(char c: s)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end(), greater<int> ());    // reverse order

        // set to store unique frequencies
        unordered_set<int> st;
        int ops = 0;    // will store number of operations/deletions
        for(int i: freq)
        {
            int val = i;
            while(val > 0 && st.find(val) != st.end())  // search for a valid frequency
                val--;
            ops += (i - val);       // adding no of deletions
            st.insert(val);         // inserting the freq in set
        }

        return ops;
    }
};