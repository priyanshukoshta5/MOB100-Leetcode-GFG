class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int mini = salary[0], maxi = salary[0];
        int sum = 0;
        for(int i: salary)
        {
            sum += i;
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        
        return (sum - mini - maxi)/(double)(n-2);
    }
};