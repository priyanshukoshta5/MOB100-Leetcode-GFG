// ~Editorial
class Solution {
public:
    int maximumLength(string s) {
        // Create a map of strings to store the count of all substrings.
        map<string, int> count;
        for (int start = 0; start < s.length(); start++) {
            string currString;
            for (int end = start; end < s.length(); end++) {
                // If the string is empty, or the current character is equal to
                // the previously added character, then add it to the map.
                // Otherwise, break the iteration.
                if (currString.empty() or currString.back() == s[end]) {
                    currString.push_back(s[end]);
                    count[currString]++;
                } else {
                    break;
                }
            }
        }

        // Create a variable ans to store the longest length of substring with
        // frequency atleast 3.
        int ans = 0;
        for (auto i : count) {
            string str = i.first;
            if (i.second >= 3 && str.length() > ans) ans = str.length();
        }
        if (ans == 0) return -1;
        return ans;
    }
};

// class Solution {
// public:
//     int maximumLength(string s) {
//         int n = s.length();
        
//         unordered_map<char, vector<int>> mp;
//         int i = 0, j = 0;
//         while(j < n)
//         {
//             char c = s[j];
//             while(j < n && s[j] == c)
//                 j++;
//             mp[c].push_back(j - i);
//             i = j;
//         }

//         for(auto x: mp)
//         {
//             sort(x.second.begin(), x.second.end());
//             cout<<x.first<<" : ";
//             for(auto i: x.second)
//                 cout<<i<<" ";
//             cout<<endl;
//         }

//         int ans = -1;
//         for(auto x: mp)
//         {
//         //     cout<<x.second.size()<<endl;
//             if(x.second.size() >= 3)
//                 ans = max(ans, x.second[x.second.size() - 3]);
//             else if(x.second.size() == 2)
//             {
//                 int l1 = x.second.front();
//                 int l2 = x.second.back();
//                 if(l1 == l2 && l1 > 1)
//                     ans = max(ans, x.second.front() - 1);
//                 else if(l1 < l2 && l2 == 2)
//                     ans = max(ans, 1);
//                 else if(l1 < l2)
//                     ans = max(ans, l2 - 2);
//             }
//             else if(x.second.back() > 2)
//                 ans = max(ans, x.second.back() - 2);
//         }

//         if(ans == 0)
//             ans = -1;
//         return ans;
//     }
// };