bool compare(string &a, string &b){
    return a.length() < b.length();
}

class Solution {
private:
    bool isPredecessor(string &pre, string &word){
        if((word.length() - pre.length()) != 1)
            return false;

        int i = 0, j = 0;
        bool flag = false;  // will note whether a char is diff or not
        while(i < pre.length())
        {
            if(pre[i] == word[j])   // if equal continue moving
            {
                i++;
                j++;
            }
            else if(flag == false)      // if a char is not matched move, insert it and move next
            {
                flag = true;
                j++;
            }  
            else                        // if more than 1 char not match, return false;
                return false;
        }

        return true;    // possible
    }

    int dfs(int node, vector<vector<int>> &adj, vector<int> &dp){
        if(dp[node] != -1)
            return dp[node];

        int chain = 0;

        for(int adjNode: adj[node])
            chain = max(chain, dfs(adjNode, adj, dp));

        return dp[node] = 1 + chain;
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), compare);

        vector<vector<int>> adj(n);     // directed graph, predecessor to word

        for(int j = n - 1; j > 0; j--)
        {
            int i = j - 1;

            // skipping all words with same length
            while(i >= 0 && words[i].length() == words[j].length())
                i--;

            // moving only to the words with length difference == 1
            while(i >= 0 && (words[j].length() - words[i].length()) == 1)
            {
                if(isPredecessor(words[i], words[j]))
                    adj[i].push_back(j);
                i--;
            }
        }

        // printing the graph
        // for(int i = 0; i < n; i++)
        // {
        //     cout<<words[i]<<" : ";
        //     for(int it: adj[i])
        //         cout<<words[it]<<" ";
        //     cout<<endl;
        // }

        int ans = 1;

        // will store the longest path from each node
        vector<int> dp(n, -1);

        // moving on each node to get the longest chain
        for(int i = 0; i < n; i++)
        {
            if(dp[i] == -1)
                ans = max(ans, dfs(i, adj, dp));
        }

        return ans;
    }
};