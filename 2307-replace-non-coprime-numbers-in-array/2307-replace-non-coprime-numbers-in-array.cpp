class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> stk;
        for(int i: nums){
            stk.push(i);

            bool flag = true;
            while(flag && stk.size() > 1){
                long long a = stk.top(); stk.pop();
                long long b = stk.top(); stk.pop();
                long long gcd = __gcd(a, b);
                if(gcd > 1){
                    long long lcm = (a * b) / gcd;
                    stk.push(lcm);
                }
                else{
                    flag = false;
                    stk.push(b);
                    stk.push(a);
                }
            }
        }

        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};