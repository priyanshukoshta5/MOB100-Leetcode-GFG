class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> maxH;

        for(vector<int> cls: classes){
            int pass = cls[0];
            int total = cls[1];
            double passRatio = pass / (1.0 * total);
            double newPassRatio = (pass + 1) / (1.0 * (total + 1));
            maxH.push({newPassRatio - passRatio, {pass, total}});
        }

        while(extraStudents--){
            auto top = maxH.top();
            maxH.pop();
            // cout<<top.first<<" "<<top.second.first<<" "<<top.second.second<<endl;
            int pass = top.second.first + 1;
            int total = top.second.second + 1;
            double passRatio = pass / (1.0 * total);
            double newPassRatio = (pass + 1) / (1.0 * (total + 1));

            maxH.push({newPassRatio - passRatio, {pass, total}});
        }

        double ans = 0;
        while(!maxH.empty()){
            auto top = maxH.top();
            int pass = top.second.first;
            int total = top.second.second;
            double passRatio = pass / (1.0 * total);
            ans += passRatio;
            // cout<<top.first<<" "<<top.second.first<<" "<<top.second.second<<endl;
            maxH.pop();
        }

        ans = ans / classes.size();

        return ans;
    }
};