//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    bool isDigit(char ch){
        return ch >= '0' && ch <= '9';
    }
  
  public:
    long long ExtractNumber(string sentence) {
        long long ans = -1;
        int i = 0;
        while(i < sentence.length())
        {
            if(!isDigit(sentence[i]))
            {
                i++;
                continue;
            }
            
            bool flag = true;
            long long temp = 0;
            while(i < sentence.length() && isDigit(sentence[i]))
            {
                if(sentence[i] == '9')
                    flag = false;
                temp = temp * 10;
                temp += (sentence[i] - '0');
                i++;
            }
            
            if(flag)
                ans = max(ans, temp);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends