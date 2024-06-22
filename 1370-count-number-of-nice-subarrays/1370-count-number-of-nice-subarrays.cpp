// ~ Editorial

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int subarrays = 0, initialGap = 0, qsize = 0, start = 0;
        for (int end = 0; end < nums.size(); end++) {
            // If current element is odd, increment qsize by 1.
            if (nums[end] % 2 == 1) {
                qsize++;
            }
            // If qsize is k, calculate initialGap and add it in the answer.
            if (qsize == k) {
                initialGap = 0;
                // Calculate the number of even elements in the beginning of
                // subarray.
                while (qsize == k) {
                    qsize -= nums[start] % 2;
                    initialGap++;
                    start++;
                }
            }
            subarrays += initialGap;
        }

        return subarrays;
    }
};

// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int odd = 0;
//         int i = 0, j = 0;
//         int ans = 0;
//         int before = 1, after = 1;
//         while(j < nums.size())
//         {
//             // cout<<odd<<" - "<<i<<" "<<j<<endl;
//             if(nums[j] % 2 == 1)
//                 odd++;
//             if(odd == k)
//             {
//                 while(i <= j && nums[i] % 2 == 0)
//                 {
//                     i++;
//                     before++;
//                 }

//                 j++;
//                 while(j < nums.size() && nums[j] % 2 == 0)
//                 {
//                     j++;
//                     after++;
//                 }

//                 ans += (before * after);
//                 cout<<before<<" "<<after<<endl;

//                 before = after;
//                 after = 1;
//                 odd--;
//             }
//             else
//                 j++;
//         }
//         return ans;
//     }
// };