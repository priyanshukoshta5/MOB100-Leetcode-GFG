//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
private:
    bool isPalindrome(string& s, int i, int j){
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
public:
    int addMinChar(string str){    
        int maxPalindrome = 0;
        for(int k=0; k<str.length(); k++)
            if(isPalindrome(str, 0, k))
                maxPalindrome = k+1;
        
        return str.length()-maxPalindrome;
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
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends