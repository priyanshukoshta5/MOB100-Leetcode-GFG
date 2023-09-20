//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            vector<int> binary(16);
            for(int i = 15; i >= 0; i--)
            {
                binary[i] = n % 2;
                n = n >> 1;
            }
            
            d = d % 16;
            vector<int> left(16, 0);
            vector<int> right(16, 0);
            for(int i = 0; i < 16; i++)
            {
                left[(i + (16 - d)) % 16] = binary[i];
                right[(i + d) % 16] = binary[i];
            }
            
            int ans1 = 0;
            int ans2 = 0;
            int power = 1;
            for(int i = 15; i >= 0; i--)
            {
                ans1 += left[i] * power;
                ans2 += right[i] * power;
                power = power * 2;
            }
            
            return {ans1, ans2};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends