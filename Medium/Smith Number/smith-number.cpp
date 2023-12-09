//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
    int digitSum(int n){
        int sum = 0;
        while(n > 0)
        {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
    
    int primeFactorDigitSum(int n){
        int sum = 0;
        int val = n;
        for(int i = 2; i <= n / 2; i++)
        {
            while(val % i == 0)
            {
                sum += digitSum(i);
                val = val / i;
            }
        }
        
        return sum;
    }
    
  public:
    int smithNum(int n) {
        // int sum1 = digitSum(n);
        // int sum2 = primeFactorDigitSum(n);
        // cout<<sum1<<" "<<sum2<<endl;
        return digitSum(n) == primeFactorDigitSum(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends