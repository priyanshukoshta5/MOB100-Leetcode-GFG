//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int sign = 1;
        
        int i = 0;
        if(s[i] == '-')
        {
            sign = -1;
            i++;
        }
        
        int num = 0;
        while(i < s.length())
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10;
                num = num + (s[i] - '0');
            }
            else
                return -1;
            i++;
        }
        
        return num * sign;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends