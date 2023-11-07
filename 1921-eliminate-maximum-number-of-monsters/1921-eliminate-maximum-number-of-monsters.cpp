class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        
        vector<double> arrivals;
        for(int i = 0; i < n; i++)
            arrivals.push_back(dist[i] / (1.0 * speed[i]));
        sort(arrivals.begin(), arrivals.end());

        int weaponTime = 0;
        for(int i = 0; i < n; i++)
        {
            if(weaponTime >= arrivals[i])
                break;
            
            weaponTime++;
        }

        return weaponTime;
    }
};