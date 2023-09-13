//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if((S > N*9) || (S == 0 && N > 1))
            return "-1";
            
        string num = "";
        int i = 1, sum = S;
        while(i <= N)
        {
            int curDigit = sum >= 9 ? 9 : sum % 9;
            num.push_back('0' + curDigit);
            sum -= curDigit;
            i++;
        }
        
        return num;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends