// ~Editorial
class Solution {
public:
    string shortestPalindrome(string s) {
        int length = s.length();
        if (length == 0) {
            return s;
        }

        // Find the longest palindromic prefix
        int left = 0;
        for (int right = length - 1; right >= 0; right--) {
            if (s[right] == s[left]) {
                left++;
            }
        }

        // If the whole string is a palindrome, return the original string
        if (left == length) {
            return s;
        }

        // Extract the suffix that is not part of the palindromic prefix
        string nonPalindromeSuffix = s.substr(left);
        string reverseSuffix =
            string(nonPalindromeSuffix.rbegin(), nonPalindromeSuffix.rend());

        // Form the shortest palindrome by prepending the reversed suffix
        return reverseSuffix + shortestPalindrome(s.substr(0, left)) +
               nonPalindromeSuffix;
    }
};


// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         int l = s.length() - 1;
//         while(l >= 0)
//         {
//             int i = 0, j = l;
//             while(i < j && s[i] == s[j])
//             {
//                 i++;
//                 j--;
//             }
//             if(i >= j)
//                 break;
//             l--;
//         }

//         string ans = s.substr(l + 1);
//         // cout<<l + 1<<" "<<ans<<endl;

//         reverse(ans.begin(), ans.end());
//         ans.append(s);

//         return ans;
//     }
// };