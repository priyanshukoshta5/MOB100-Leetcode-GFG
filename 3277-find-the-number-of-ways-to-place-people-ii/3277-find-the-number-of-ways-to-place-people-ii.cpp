class Solution {
public:
    bool static compare(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }

    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(), points.end(), compare);

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(i == j)
                    continue;

                const auto &A = points[i];
                const auto &B = points[j];
                
                if(A[0] <= B[0] && A[1] >= B[1]){
                    bool flag = true;
                    for(int k = i + 1; k < j; k++){
                        if(k == i || k == j)
                            continue;
                        
                        const auto &C = points[k];
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