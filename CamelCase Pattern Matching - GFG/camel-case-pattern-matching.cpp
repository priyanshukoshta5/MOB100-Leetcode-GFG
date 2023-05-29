//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool isCapital(char ch){
        return ch >= 'A' && ch <= 'Z';
    }
    
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        vector<string> ans;
        
        for(string s: Dictionary)
        {
            int i = 0, j = 0;
            while(i < s.length() && j < Pattern.length())
            {
                if(isCapital(s[i]))
                {
                    if(s[i] == Pattern[j])
                        j++;
                    else
                        break;
                }
                i++;
            }
            
            if(j == Pattern.length())
                ans.push_back(s);
        }
        
        if(ans.size() == 0)
            return {"-1"};
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends