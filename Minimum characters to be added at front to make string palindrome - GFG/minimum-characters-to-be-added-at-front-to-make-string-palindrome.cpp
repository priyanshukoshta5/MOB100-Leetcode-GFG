//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int minChar(string A){
        int n = A.length();
        string rev = A;
        reverse(rev.begin(), rev.end());
        string concat = A + "$" + rev;
        
        int size = concat.length();
        int len = 0;
        vector<int> lps(size);
        lps[0] = 0;
        int i = 1;
        while(i < size)
        {
            if(concat[i] == concat[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                    len = lps[len-1];
            }
        }
        
        return n - lps[size-1];
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends