//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
        int topBound = 1, bottomBound = n-1;
        int leftBound = 0, rightBound = m-1;
 		int i = 0, j = 0;
 		int cnt = k - 1;
 		while(cnt > 0)
 		{
 		    while(cnt > 0 && j < rightBound)
 		    {
 		        j++;
 		        cnt--;
 		    }
 		    rightBound--;
 		    
 		    while(cnt > 0 && i < bottomBound)
 		    {
 		        i++;
 		        cnt--;
 		    }
 		    bottomBound--;
 		    
 		    while(cnt > 0 && j > leftBound)
 		    {
 		        j--;
 		        cnt--;
 		    }
 		    leftBound++;
 		    
 		    while(cnt > 0 && i > topBound)
 		    {
 		        i--;
 		        cnt--;
 		    }
 		    topBound++;
 		}
 		
 		return a[i][j];
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
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends