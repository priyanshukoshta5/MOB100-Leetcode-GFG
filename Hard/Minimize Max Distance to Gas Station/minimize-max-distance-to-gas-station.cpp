//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    bool check(vector<int> &stations, int k, double mid){
        int cnt = 0;
        for(int i = 1; i < stations.size(); i++)
        {
            int req = ceil((stations[i] - stations[i - 1]) / mid) - 1;
            cnt += req;
        }
        return cnt <= k;
    }
    
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        double maxD = 0, l = 0, r = 1e9;
        while((r - l) > 1e-6)
        {
            double mid = (l + r) / 2;
            if(check(stations, k, mid))
            {
                maxD = mid;
                r = mid;
            }
            else
                l = mid;
        }
        
        return maxD;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends