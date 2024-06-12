//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
        {
            int num = i;
            while(num > 0)
            {
                if(num % 10 == 4)
                {
                    cnt++;
                    break;
                }
                num = num / 10;
            }
        }
        return cnt;
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
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends