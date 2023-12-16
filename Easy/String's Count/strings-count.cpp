//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


#define ll long long int

long long int countStr(long long int n){
    ll A = 1;                                  // only A
    ll AB1 = n;                                // A with single B
    ll AC1 = n;                                // A with single C
    ll AC2 = (n * (n - 1)) / 2;                // A with 2 C
    ll AB1C1 = n * (n - 1);                    // A with 1 B & 1 C
    ll AB1C2 = n * (n - 1) * (n - 2) / 2;      // A with 1 B & 2 C
    // cout<<A<<" "<<AB1<<" "<<AC1<<" "<<AC2<<" "<<AB1C1<<" "<<AB1C2<<endl;
    return (A + AB1 + AC1 + AC2 + AB1C1 + AB1C2);
}