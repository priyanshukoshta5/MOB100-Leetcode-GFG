//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    bool isDigit(char &ch)
    {
        return ch>='0' && ch<='9';
    }
  
    string reverseEqn (string s)
    {
        string rev = "";
        int i=0;
        while(i < s.length())
        {
            string num;
            while(i < s.length() && isDigit(s[i]))
            {
                num.push_back(s[i]);
                i++;
            }
            
            rev = num + rev;
            if(i < s.length())
                rev = s[i] + rev;
            i++;
        }
        return rev;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends