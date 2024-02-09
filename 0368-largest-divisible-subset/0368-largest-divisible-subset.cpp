// ~ cs_iitian

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> groupSize(n, 1), prevElement(n, -1);
        int maxIndex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && groupSize[i] < groupSize[j] + 1) {
                    groupSize[i] = groupSize[j] + 1;
                    prevElement[i] = j;
                }
            }
            if (groupSize[i] > groupSize[maxIndex]) {
                maxIndex = i;
            }
        }

        vector<int> result;
        for (int i = maxIndex; i != -1; i = prevElement[i]) {
            result.insert(result.begin(), nums[i]);
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         int n = nums.size();

//         sort(nums.begin(), nums.end());
//         int maxLen = 0;
//         int ansVal;
//         for(int i = 0; i < n; i++)
//         {
//             int cnt = 0;
//             for(int j = i; j < n; j++)
//                 if(nums[j] % nums[i] == 0)
//                     cnt++;
//             if(cnt > maxLen)
//             {
//                 maxLen = cnt;
//                 ansVal = nums[i];
//             }
//         }

//         vector<int> ans;
//         for(int i = 0; i < n; i++)
//         {
//             if(nums[i] % ansVal == 0)
//                 ans.push_back(nums[i]);
//         }

//         return ans;
//     }
// };