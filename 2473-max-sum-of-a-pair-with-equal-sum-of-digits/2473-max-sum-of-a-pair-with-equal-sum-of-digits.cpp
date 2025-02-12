class Solution {
private:
    int digitSum(int num){
        int sum = 0;
        while(num > 0)
        {
            sum += (num % 10);
            num = num / 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> digNumMax;
        for(int i: nums)
        {
            int digSum = digitSum(i);
            if(digNumMax.find(digSum) != digNumMax.end())
            {
                ans = max(ans, digNumMax[digSum] + i);
                digNumMax[digSum] = max(digNumMax[digSum], i);
            }
            else
                digNumMax[digSum] = i;
        }
        if(ans > 0)
            return ans;
        return -1;
    }
};