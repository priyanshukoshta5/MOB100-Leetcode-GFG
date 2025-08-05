class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        for(int f: fruits){
            bool flag = false;
            for(int j = 0; j < baskets.size(); j++){
                if(baskets[j] >= f){
                    baskets[j] = 0;
                    flag = true;
                    break;
                }
            }
            if(!flag)
                ans++;
        }
        return ans;
    }
};