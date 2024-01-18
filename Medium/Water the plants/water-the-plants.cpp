//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

// Editorial

class Solution{
    public:
    int min_sprinklers(int arr[], int N)
    {
        vector<pair<int, int> > V;
        
        for (int i = 0; i < N; i++) {
            if (arr[i] > -1) {
                V.push_back(
                    pair<int, int>(i - arr[i], i + arr[i]));
            }
        }
        sort(V.begin(), V.end());
     
        int maxRight = 0;
        int res = 0;
     
        int i = 0;
     
        while (maxRight < N) {
     
     
            if (i == V.size() || V[i].first > maxRight) {
                return -1;
            }
            int currMax = V[i].second;
     
            while (i + 1 < V.size()
                   && V[i + 1].first <= maxRight) {
     
                i++;
                currMax = max(currMax, V[i].second);
            }
     
            if (currMax < maxRight) {
                return -1;
            }
            res++;
     
            maxRight = currMax + 1;
     
            i++;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends