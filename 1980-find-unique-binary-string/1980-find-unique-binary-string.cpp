// ~ Editorial
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); i++) 
        {
            char curr = nums[i][i];
            ans += curr == '0' ? '1' : '0';
        }
        
        return ans;
    }
};

// class Solution {
// private:
//     int binaryToDecimal(string &s){
//         int num = 0;
//         int pow = 1;
//         for(int i = s.length() - 1; i >= 0; i--)
//         {
//             char ch = s[i];
//             num += (pow * (ch - '0'));
//             pow = pow * 2;
//         }
//         return num;
//     }

//     string decimalToBinary(int num){
//         string res = "";
//         while(num != 0)
//         {
//             res.push_back('0' + num % 2);
//             num = num / 2;
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }

// public:
//     string findDifferentBinaryString(vector<string>& nums) {
//         vector<int> v;
//         for(string s: nums)
//             v.push_back(binaryToDecimal(s));

//         sort(v.begin(), v.end());

//         int missing = v.size();
//         for(int i = 0; i < v.size(); i++)
//         {
//             if(i != v[i])
//             {
//                 missing = i;
//                 break;
//             }
//         }

//         string ans = decimalToBinary(missing);

//         reverse(ans.begin(), ans.end());
//         while(ans.length() < nums[0].length())
//             ans.push_back('0');
//         reverse(ans.begin(), ans.end());

//         return ans;
//     }
// };