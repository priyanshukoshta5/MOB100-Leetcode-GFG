//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        queue<char> q;
        int freq[26] = {0};
        for(char c: S)
        {
            freq[c-'a']++;
            if(freq[c-'a'] == 1)
                q.push(c);
        }
        while(!q.empty() && freq[q.front()-'a'] > 1)
            q.pop();
        
        return q.empty() ? '$' : q.front() ;
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends