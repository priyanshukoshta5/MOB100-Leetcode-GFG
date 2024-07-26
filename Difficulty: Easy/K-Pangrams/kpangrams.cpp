//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        
        int len=str.length();
        int n=0;
        unordered_map<char,int>mp;
        for(int i=0;i<len;i++){
            if(str[i]!=' '){
                mp[str[i]]++;
            }
            else{
                n++;
            }
        }
        
        if(len-n<26){
            return false;
        }
        
        int m=mp.size();
        
        if(m==26){
            return true;
        }
        
        if(26-m<=k){
            return true;
        }
        return false;
    }

    // bool kPangram(string str, int k) {
    //     set<char> st;
    //     for(char ch: str)
    //     {
    //         if(ch >= 'a' && ch <= 'z')
    //             st.insert(ch);
    //     }
    //     // cout<<st.size()<<endl;
    //     int extra = str.length() - st.size();
    //     return k >= (26 - st.size()) && extra >= k;
    // }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends