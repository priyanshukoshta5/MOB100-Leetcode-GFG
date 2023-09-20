class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        
        int ans = n + 1;

        long long leftSum = 0;
        for(int i = 0; i < n; i++)
        {
            leftSum += nums[i];   
            if(leftSum == x)
                ans = i + 1;
        }    

        // target is greater than the sum of all elements
        if(x > leftSum)
            return -1;

        long long rightSum = 0;
        int j = n - 1;
        for(int i = n - 1; i >= 0; i--)
        {
            rightSum += nums[i];
            if(rightSum > x)
                break;

            while(j >= 0 && leftSum > (x - rightSum))
            {
                leftSum -= nums[j];
                j--;
            }

            if(j >= 0 && leftSum == (x - rightSum))
                ans = min(ans, (n - i) + (j + 1));
            else if(rightSum == x)
                ans = min(ans, (n - i));
        }

        // if the sum == x is not possible
        if(ans == n + 1)
            return -1;
        return ans;
    }
};