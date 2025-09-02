class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;

                vector<int> A = points[i];
                vector<int> B = points[j];
                
                if(A[0] <= B[0] && A[1] >= B[1]){
                    bool flag = true;
                    for(int k = 0; k < n; k++){
                        if(k == i || k == j)
                            continue;
                        
                        auto C = points[k];
                        if(C[1] >= B[1] && C[0] <= B[0] && C[1] <= A[1] && C[0] >= A[0]){
                            flag = false;
                            break;
                        }
                    }
                    
                    if(flag)
                        ans++;
                }
            }
        }

        return ans;
    }
};