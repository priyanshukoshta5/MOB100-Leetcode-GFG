//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private:
    void findAll(int n, int one, int zero, string &num, vector<string> &ans){
        if(one < zero)
            return;
            
        if(n == 0)
        {
            if(one >= zero)
                ans.push_back(num);
            return;
        }
        
        num.push_back('1');
        findAll(n - 1, one + 1, zero, num, ans);
        num.pop_back();
        
        num.push_back('0');
        findAll(n - 1, one, zero + 1, num, ans);
        num.pop_back();
        
        return;
    }
    
public:	
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    string num;
	    findAll(n, 0, 0, num, ans);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends