//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        if(S >= (D*9) || S == 1)
            return "-1";
        
        string ans;
        int digitsLeft = D;
        int sum = S;
        while(digitsLeft > 1)
        {
            if(sum == 1)
                ans.push_back('0');
            else if(sum <= 9)
            {
                ans.push_back(sum-1+'0');
                sum = 1;
            }
            else
            {
                ans.push_back(9+'0');
                sum -= 9;
            }
            digitsLeft--;
        }
        ans.push_back(sum+'0');
        
        int i=0;
        while(ans[i] == '9')
            i++;
        if(i == 0)
        {
            ans[i]--;
            ans[i+1]++;
        }
        else
        {
            ans[i-1]--;
            ans[i]++;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends