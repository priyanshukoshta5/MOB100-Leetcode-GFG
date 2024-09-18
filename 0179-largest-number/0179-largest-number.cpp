bool compare(int a, int b){
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        if(nums[0] == 0)
            return "0";
        string ans = "";
        for(int i: nums)
            ans.append(to_string(i));
        return ans;
    }
};