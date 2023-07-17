//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    queue<char> q;
		    int freq[26] = {0};
		    
		    string ans = "";
		    for(char ch: A)
		    {
		        freq[ch-'a']++;
		        if(freq[ch-'a'] == 1)
                    q.push(ch);
                
                while(!q.empty() && freq[q.front()-'a'] > 1)
                    q.pop();
                    
                if(q.empty())
                    ans.push_back('#');
                else
                    ans.push_back(q.front());
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends