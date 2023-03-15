//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    private:
    bool isPalindrome(string& s)
    {
        for(int i=0,j=s.length()-1; i<j; i++,j--)
            if(s[i] != s[j])
                return false;
                
        return true;
    }
    
    public:
    int specialPalindrome(string s1, string s2){
        int ans = -1;
        
        int n = s1.length();
        int m = s2.length();
        string temp = s1;
        for(int i=0; i<(n-m+1); i++)
        {
            temp = s1;
            int cost = 0;
            for(int j=0; j<m; j++)
            {
                if(temp[i+j] != s2[j])
                {
                    temp[i+j] = s2[j];
                    cost++;
                }
            }
            
            for(int x=0, y=n-1; x<y; x++, y--)
            {
                if((x>=i && x<(i+m)))
                {
                    if((y>=i && y<(i+m)))
                        continue;
                        
                    if(temp[x] != temp[y])
                    {
                        temp[y] = temp[x];
                        cost++;
                    }
                }
                else if((y>=i && y<(i+m)))
                {
                    if(temp[x] != temp[y])
                    {
                        temp[x] = temp[y];
                        cost++;
                    }
                }
                else if(temp[x] != temp[y])
                {
                    temp[x] = temp[y];
                    cost++;
                }
            }
            
            // cout<<temp<<" "<<cost<<endl;
            
            if(isPalindrome(temp))
            {
                if(ans == -1)
                    ans = cost;
                else
                    ans = min(ans,cost);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends