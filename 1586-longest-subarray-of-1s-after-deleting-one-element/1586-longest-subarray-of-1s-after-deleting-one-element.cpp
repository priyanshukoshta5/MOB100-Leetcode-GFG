class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        
        bool onesFlag = true;
        int prevOnes = 0, ones = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i - 1] == 0 && nums[i] == 0){  // "...00..."
                onesFlag = false;
                prevOnes = 0;
            }   
            if(i > 0 && nums[i - 1] == 1 && nums[i] == 0){  // "...10..."
                onesFlag = true;   
                prevOnes = ones;
            }   

            if(nums[i] == 1){
                ones++;
                if(onesFlag)
                    ans = max(ans, prevOnes + ones);
                else
                    ans = max(ans, ones);
            }
            else{
                ones = 0;
            }
        }

        if(ans == nums.size())  // if complete array of ones
            ans--;
        return ans;
    }
};