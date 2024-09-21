class Solution {
private:
    void createAll(int val, int n, vector<int> &ans){
        // cout<<val<<" ";
        
        if(val > 0)
            ans.push_back(val);
        
        val = val * 10;
        if(val > 0 && val <= n)
            createAll(val, n, ans);
        for(int i = 1; i <= 9; i++)
        {
            if((val + i) > n)
                break;
            createAll(val + i, n, ans);
        }

        return;
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        createAll(0, n, ans);

        return ans;
    }
};