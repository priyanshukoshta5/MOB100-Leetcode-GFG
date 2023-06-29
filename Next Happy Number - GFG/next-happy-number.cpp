//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
private:
    int sqDigSum(int n){
        int sqSum = 0;
        while(n > 0)
        {
            sqSum += pow(n%10, 2);
            n = n/10;
        }
        return sqSum;
    }
    
public:
    int nextHappy(int N){
        int k = N+1;
        while(true)
        {
            int sum = k;
            for(int i = 0; i < 7; i++)
            {
                sum = sqDigSum(sum);
                if(sum == 1)
                    return k;
            }
            k++;
        }
        return 0;
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
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends