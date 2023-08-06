//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    void permutations(string& s, vector<string> &ans, vector<int>& vis, string &temp){
        if(temp.length() == s.length())
        {
            ans.push_back(temp);
            return;
        }
        
        for(int i = 0; i < s.length(); i++)
        {
            if(vis[i] == 0)
            {
                vis[i] = 1;
                temp.push_back(s[i]);
                permutations(s, ans, vis, temp);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }
    
    public:
    //Complete this function
    
    vector<string> permutation(string S)
    {
        vector<string> ans;
        int n = S.length();
        vector<int> vis(n, 0);
        string temp = "";
        permutations(S, ans, vis, temp);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends