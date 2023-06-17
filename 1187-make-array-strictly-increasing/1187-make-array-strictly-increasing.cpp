class Solution {
    
// My Solution
    
// private:
//     map<pair<int,int>,int> dp;

//     int solve(vector<int>& arr1, int i, vector<int>& arr2, int prev){
//         if(i == arr1.size())
//             return 0;

//         if(dp.find({i, prev}) != dp.end())
//             return dp[{i, prev}];

//         // Do not replace
//         int not_rep = -1;
//         if(arr1[i] > prev)
//             not_rep = solve(arr1, i+1, arr2, arr1[i]);

//         // Replace it 
//         int rep = -1;
//         int ind = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
//         if(ind != arr2.size())
//         {
//             int val = arr2[ind];
//             rep = solve(arr1, i+1, arr2, val); 
//         }

//         int ans;

//         if(not_rep == -1 && rep == -1) ans = -1;
//         else if(not_rep == -1)  ans = 1 + rep;     // +1 for 1 operation
//         else if(rep == -1) ans = not_rep;
//         else ans = min(not_rep, 1 + rep);          // +1 for 1 operation

//         return dp[{i, prev}] = ans;
//     }

// public:
//     int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
//         sort(arr2.begin(), arr2.end());
//         return solve(arr1, 0, arr2, -1);
//     }
    
    
// ~votrubac
public:
    short dp[2001][2001][2] = {}, max_val = 2002;
    short dfs(vector<int>& t, vector<int>& s, int i, int j, bool prev_t) {
        if (i >= t.size()) 
          return 0;
        int prev = prev_t ? i == 0 ? INT_MIN : t[i - 1] : s[j];
        j = upper_bound(begin(s) + j, end(s), prev) - begin(s);
        if (dp[i][j][prev_t] == 0) {
            dp[i][j][prev_t] = max_val;
            if (j < s.size())
                dp[i][j][prev_t] = dfs(t, s, i + 1, j, false) + 1;
            if (prev < t[i])
                dp[i][j][prev_t] = min(dp[i][j][prev_t], dfs(t, s, i + 1, j, true));
        }
        return dp[i][j][prev_t];
    }
    int makeArrayIncreasing(vector<int>& t, vector<int>& s) {
      sort(begin(s), end(s));
      auto res = dfs(t, s, 0, 0, true);
      return res >= max_val ? -1 : res;
    }
};