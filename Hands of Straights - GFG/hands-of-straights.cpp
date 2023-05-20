//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
        if(N%groupSize != 0)
            return false;
            
        map<int,int> freq;
        int mini = hand[0];
        for(int i: hand)
        {
            mini = min(mini, i);
            freq[i]++;
        }
        
        int cnt = 0;
        while(cnt < N)
        {
            for(int i=mini; i<mini+groupSize; i++)
            {
                if(freq.find(i) == freq.end())
                    return false;
                else
                {
                    freq[i]--;
                    if(freq[i] == 0)
                        freq.erase(i);
                }
            }
            cnt += groupSize;
            if(freq.size() == 0)
                break;
            mini = (*freq.begin()).first;
        }
        
        if(cnt != N)
            return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends