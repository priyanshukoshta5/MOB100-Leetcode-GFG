//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        int num = 0;
        int prev = 0;
        for(int i = 31; i >= 0; i--)
        {
            int temp = ((n >> i) & 1);
            prev = temp ^ prev;
            num = num | (prev << i);
            // cout<<temp<<" "<<prev<<endl;
        }
        return num;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends