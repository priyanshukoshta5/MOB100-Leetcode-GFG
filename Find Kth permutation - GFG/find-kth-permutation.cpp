//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
private:
    void kthPermutation(int n, int k, vector<char>& nums, int allPerms, string& ans){
        if(nums.size() == 0) return;
            
        // Calculating the size of each N part for each number
        int partSize = allPerms / n;
        
        // Finding the index of Integer to select
        int partInd = k / partSize;
        
        // Pushing the Integer at that index in the answer
        ans.push_back(nums[partInd]);
        
        // Erasing that index(Integer) from Integers space
        nums.erase(nums.begin() + partInd);
        
        // Calling for next place to fill
        kthPermutation(n-1, k % partSize, nums, allPerms / n, ans);
    }

public:
    string kthPermutation(int n, int k){
        vector<char> nums(n);
        int allPerms = 1;   // will store number of all possible permutations
        for(int i=0; i<n; i++)
        {
            nums[i] = (i+1 + '0');
            allPerms *= (i+1);
        }
            
        string ans = "";
        kthPermutation(n, k-1, nums, allPerms, ans);    // here (k-1) because we are using 0-based indexing
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends