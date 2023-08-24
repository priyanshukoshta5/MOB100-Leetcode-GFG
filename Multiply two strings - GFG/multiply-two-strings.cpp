//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        string num1 = s1;
        reverse(num1.begin(), num1.end());
        int sign1 = 1;
        if(s1[0] == '-')
        {
            sign1 = -1;
            num1.pop_back();
        }
        
        string num2 = s2;
        reverse(num2.begin(), num2.end());
        int sign2 = 1;
        if(s2[0] == '-')
        {
            sign2 = -1;
            num2.pop_back();
        }
        
        int rem = 0;
        string ans;
        
        for(int i = 0; i < num1.size(); i++)
        {
            string tempRes;
            rem = 0;
            
            for(int j = 0; j < num2.size(); j++)
            {
                int temp = (num1[i] - '0') * (num2[j] - '0') + rem;
                tempRes.push_back('0' + (temp % 10));
                rem = temp / 10;
            }
            if(rem != 0)
                tempRes.push_back('0' + rem);
                
            int j = i;
            rem = 0;
            for(char c: tempRes)
            {
                int temp = rem + (c - '0');
                
                if(ans.length() > j)
                {
                    temp += (ans[j] - '0');
                    ans[j] = ('0' + temp % 10);
                }
                else
                    ans.push_back('0' + temp % 10);
                    
                rem = temp / 10;
                j++;
            }
            if(rem != 0)
            {
                if(ans.length() > j)
                    ans[j] = ('0' + rem);
                else
                    ans.push_back('0' + rem);
            }
        }
        
        while(ans.length() > 0 && ans[ans.length() - 1] == '0')
            ans.pop_back();
        
        if((sign1 * sign2) == -1)
            ans.push_back('-');
            
        reverse(ans.begin(), ans.end());
        
        return ans;
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends