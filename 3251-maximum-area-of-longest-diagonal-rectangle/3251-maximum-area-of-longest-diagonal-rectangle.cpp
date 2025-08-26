class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans = 0;
        int maxDiag = 0;
        for(auto rect: dimensions){
            int l = rect[0];
            int w = rect[1];
            int diagSq = pow(l, 2) + pow(w, 2);
            if(maxDiag < diagSq){
                maxDiag = diagSq;
                ans = l * w;
            }
            else if(maxDiag == diagSq){
                maxDiag = diagSq;
                ans = max(ans, l * w);
            }
        }
        return ans;
    }
};