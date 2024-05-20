class Solution {
private:
    int sum = 0;
    void compute(int ind, vector<int> &nums, int XOR){
        if(ind == nums.size())
        {
            sum += XOR;
            return;
        }

        // notTake
        compute(ind + 1, nums, XOR);

        // take
        compute(ind + 1, nums, XOR ^ nums[ind]);

        return;
    }

public:
    int subsetXORSum(vector<int>& nums) {
        compute(0, nums, 0);
        return sum;
    }
};