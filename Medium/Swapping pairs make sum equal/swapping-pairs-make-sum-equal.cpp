//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// ~ Nikhil Daiya


class Solution {
  public:
    int pairExist(int a[] , int n , int b[] , int m , long long aSum , long long bSum)
    {
        int low = 0 , high = m - 1 ;
        long long currASum = aSum , currBSum = bSum ;
        
        while(low < n && high >= 0)
        {
            currASum -= a[low] ;
            currASum += b[high] ;
            
            currBSum -= b[high] ;
            currBSum += a[low] ;
            
            if(currASum == currBSum)
                return 1 ;
            else if(currASum > currBSum)
                --high ;
            else
                ++low ;
                
            currASum = aSum ;
            currBSum = bSum ;
        }
        
        return -1 ;
    }
  
    int findSwapValues(int a[], int n, int b[], int m) {
        sort(a, a + n);
        sort(b, b + m);
        
        int sum1 = 0;
        for(int i = 0; i < n; i++)
            sum1 += a[i];
        
        int sum2 = 0;
        for(int i = 0; i < m; i++)
            sum2 += b[i];
        
        if(sum1 == sum2)
            return 1;
        
        if(a[0] <= b[0])
            return pairExist(a , n , b , m , sum1 , sum2) ;
        else
            return pairExist(b , m , a , n , sum2 , sum1) ;
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends