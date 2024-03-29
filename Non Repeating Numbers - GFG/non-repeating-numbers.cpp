//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Editorial

class Solution {
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Pass 1 : 
        // Get the XOR of the two numbers we need to find
        int diff = 0;
        for(int i: nums)
        	diff = i ^ diff;
        	
        // Get its last set bit
        diff &= -diff;
        
        // Pass 2 :
        vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
        for (int num : nums)
        {
            if ((num & diff) == 0) // the bit is not set
            {
                rets[0] ^= num;
            }
            else // the bit is set
            {
                rets[1] ^= num;
            }
        }
        
        if(rets[0] > rets[1])
        	swap(rets[0], rets[1]);
        	
        return rets;
    }
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends