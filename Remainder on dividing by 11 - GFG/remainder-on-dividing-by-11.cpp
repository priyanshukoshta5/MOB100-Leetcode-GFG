//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
        if(x.length() == 1)
            return int(x[0]-'0');
            
        int rem = int(x[0]-'0');
        int num = int(x[0]-'0');
        int i = 1;
        while(i < x.length())
        {
            num = rem*10 + int(x[i]-'0');
            rem = num%11;
            i++;
        }
        
        return rem;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends