//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    if((n % k) != 0)
	        return 0;
	    if(k == n || (n / k) == 2)
	        return 1;
	    
	    string pat;
	    if(s[0] == s[k] || s[0] == s[2 * k])
	        pat = s.substr(0, k);
	    else if(s[k] == s[2 * k])
	        pat = s.substr(k, k);
	    
	    int diff = -1;
	    for(int i = 0; i < n; i += k)
	    {
	        for(int j = 0; j < k; j++)
	        {
	            if(s[i + j] != pat[j])
	            {
	                if(diff != -1)
	                    return 0;
	                diff = i;
	                break;
	            }
	        }
	    }
	    
	    return 1;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends