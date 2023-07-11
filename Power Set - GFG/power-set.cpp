//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
        void getAll(int ind, string &subseq, string& s, vector<string> &ans){
            if(ind == s.length())
            {
                if(subseq.length() != 0)
                    ans.push_back(subseq);
                return;
            }
            
            getAll(ind+1, subseq, s, ans);
            
            subseq.push_back(s[ind]);
            getAll(ind+1, subseq, s, ans);
            subseq.pop_back();
        }
    
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> ans;
		    
		    string subseq = "";
		    getAll(0, subseq, s, ans);
		    
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