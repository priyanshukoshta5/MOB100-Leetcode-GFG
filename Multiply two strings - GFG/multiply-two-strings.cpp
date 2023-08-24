//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        // finding lengths of 2 string numbers
        int n1 = s1.length();
        int n2 = s2.length();
        
        string num1 = s1;                   // storing number 1 in num1
        reverse(num1.begin(), num1.end());  // reversing num1 to make it easy to multiply
        int sign1 = 1;                      // finding sign of num1
        if(s1[0] == '-')
        {
            sign1 = -1;
            num1.pop_back();                // if negative sign, then pop that sign from string num1
        }
        
        string num2 = s2;                   // storing number 1 in num1
        reverse(num2.begin(), num2.end());  // reversing num1 to make it easy to multiply
        int sign2 = 1;                      // finding sign of num2
        if(s2[0] == '-')        
        {
            sign2 = -1;
            num2.pop_back();                // if negative sign, then pop that sign from string num2
        }
        
        int rem = 0;        // variable to store 10th digit in multiplication and addition                  
        string ans;         // varialbe to store ans string
        
        for(int i = 0; i < num1.size(); i++)
        {
            string tempRes;     // will store temperatory string
            rem = 0;            // resetting rem variable
            
            // multiplying num1[i] with all the digits in num2 and storing it in tempRes
            for(int j = 0; j < num2.size(); j++)    
            {
                int temp = (num1[i] - '0') * (num2[j] - '0') + rem;
                tempRes.push_back('0' + (temp % 10));
                rem = temp / 10;
            }
            if(rem != 0)        // if we are left with a 10th digit
                tempRes.push_back('0' + rem);
                
            // addition of 'ans' and 'tempRes' (just like traditional multiplication) from j = i position (leaving 1 digit from left in every iteration)
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
            if(rem != 0)        // if we are left with a 10th digit
            {
                if(ans.length() > j)
                    ans[j] = ('0' + rem);
                else
                    ans.push_back('0' + rem);
            }
        }
        
        // removing any leading digit we will get in the final 'ans'
        while(ans.length() > 0 && ans[ans.length() - 1] == '0')
            ans.pop_back();
        
        // if the multiplication of sign of two numbers is negative add it to the 'ans' string
        if((sign1 * sign2) == -1)
            ans.push_back('-');
            
        // reversing the 'ans'
        reverse(ans.begin(), ans.end());
        
        // returning final string
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