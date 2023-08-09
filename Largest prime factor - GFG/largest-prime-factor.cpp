//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
private:
    bool isPrime(int n){
        if(n <= 1)  return false;
        if(n == 2)  return true;
        for(int i = 2; i <= sqrt(n); i++)
            if(n % i == 0)
                return false;
        return true;
    }
    
public:
    long long int largestPrimeFactor(int N){
        if(isPrime(N))
            return N;
        
        int ans = -1;
        for(int i = 2; i <= sqrt(N); i++)
        {
            if(N % i == 0)
            {
                if(isPrime(i)) ans = max(ans, i);
                if(isPrime(N / i)) ans = max(ans, N / i);
            }
        }
        
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
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends