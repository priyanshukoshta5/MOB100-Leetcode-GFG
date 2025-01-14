class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        
        vector<int> ans;
        int cnt = 0;
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++)
        {
            freq[A[i]]++;
            freq[B[i]]++;
            if(A[i] == B[i])
                cnt++;
            else
            {
                if(freq[A[i]] == 2)
                    cnt++;
                if(freq[B[i]] == 2)
                    cnt++;
            }
            
            ans.push_back(cnt);
        }

        return ans;
    }
};