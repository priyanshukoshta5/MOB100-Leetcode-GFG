//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    private:
        long long MOD = 1e9 + 7;
        
        long long myPow(long long n, long long p){
            if(n == 1 || p == 0)
                return 1;
            if(p == 1)
                return n;
                
            long long temp = myPow(n, p/2) % MOD;
            if(p % 2 == 0)
                return ( temp * temp ) % MOD;
            else
                return ( ( ( temp * temp ) % MOD) * n) % MOD;
        }
    
    public:
        long long power(int N,int R)
        {
           return myPow(N, R) % MOD;
        }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends