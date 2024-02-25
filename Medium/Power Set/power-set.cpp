//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
        void solve(int ind, string &s, string &temp, vector<string> &ans){
            if(ind == s.length())
                return;
            
            solve(ind + 1, s, temp, ans);
            
            temp.push_back(s[ind]);
            ans.push_back(temp);
            solve(ind + 1, s, temp, ans);
            temp.pop_back();
        }
    
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    string temp = "";
		    solve(0, s, temp, ans);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends