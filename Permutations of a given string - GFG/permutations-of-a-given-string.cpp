//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
        void allPermutations(string& s, vector<int> vis, string res, vector<string>& ans){
            if(res.length() == s.length())
            {
                ans.push_back(res);
                return;
            }
            
            int i = 0;
            while(i<s.length())
            {
                if(vis[i] == 0)
                {
                    char ch = s[i];
                    vis[i] = 1;
                    allPermutations(s, vis, res + ch, ans);
                    vis[i] = 0;
                    while(i<s.length() && s[i] == ch)
                        i++;
                }
                else
                    i++;
            }
        }
    
	public:
		vector<string>find_permutation(string S)
		{
		    sort(S.begin(), S.end());
		    vector<string> ans;
		    vector<int> vis(S.length(), 0);
		    allPermutations(S, vis, "", ans);
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends