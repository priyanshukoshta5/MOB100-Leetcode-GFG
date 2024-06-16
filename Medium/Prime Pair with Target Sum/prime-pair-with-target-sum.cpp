//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    bool isPrime(int n){
        if(n <= 1)
            return false;
        if(n == 2)
            return true;
        for(int i = 2; i <= sqrt(n); i++)
        {
            if(n % i == 0)
                return false;
        }
        return true;    
    }
    
    vector<int> getPrimes(int n) {
        int a = 2, b = n - 2;
        while(a <= b)
        {
            if(isPrime(a) && isPrime(b))
                return {a, b};
            a++;
            b--;
        }
        return {-1, -1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends