//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);


// } Driver Code Ends
class Solution
{
    private:
    bool isPresent(vector<vector<int>> &arr, vector<int> &temp){
        for(auto row: arr)
        {
            bool flag = true;
            for(int j = 0; j < temp.size(); j++)
            {
                if(row[j] != temp[j])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag == true)
                return true;
        }
        
        return false;
    }
    
    public:
    vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
    {
        vector<vector<int>> ans;
        
        for(int i = 0; i < row; i++)
        {
            vector<int> temp;
            for(int j = 0; j < col; j++)
                temp.push_back(M[i][j]);
                
            if(isPresent(ans, temp) == false)
                ans.push_back(temp);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	Solution ob;
    	vector<vector<int>> vec = ob.uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}

// } Driver Code Ends