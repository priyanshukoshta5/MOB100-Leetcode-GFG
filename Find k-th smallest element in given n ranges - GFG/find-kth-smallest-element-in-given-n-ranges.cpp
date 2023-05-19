//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

bool compare(vector<int> &a, vector<int> &b){
    return a[0] <= b[0];
}

class Solution{
    public:
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        sort(range.begin(), range.end(), compare);
        // for(auto x: range)
        //     cout<<x[0]<<" "<<x[1]<<endl;    
        // cout<<endl;
        
        vector<vector<int>> merged;
        for(auto x: range)
        {
            if(merged.size() == 0 || merged.back()[1] < x[0])
                merged.push_back(x);
            else if(merged.back()[0] <= x[0] && merged.back()[1] >= x[0])
                merged.back()[1] = max(merged.back()[1], x[1]);
        }
        
        // for(auto x: merged)
        //     cout<<x[0]<<" "<<x[1]<<endl;
        
        vector<int> ans;
        for(auto q: queries)
        {
            int rem = q;
            int i = 0;
            while(i < merged.size())
            {
                vector<int> rng = merged[i];
                int elements = (rng[1] - rng[0] + 1);
                if(elements >= rem)
                    break;
                else
                    rem -= elements;
                i++;
            }
            if(i == merged.size())
                ans.push_back(-1);
            else
                ans.push_back(merged[i][0] + rem - 1);
        }
        
        return ans;
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends