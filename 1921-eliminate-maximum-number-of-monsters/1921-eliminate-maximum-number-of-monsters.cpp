class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        
        priority_queue<double, vector<double>, greater<double>> arrivals;
        for(int i = 0; i < n; i++)
            arrivals.push(dist[i] / (1.0 * speed[i]));

        int monsterDefeated = 0;
        int weaponTime = 0;
        while(!arrivals.empty() && weaponTime < arrivals.top())
        {
            arrivals.pop();
            weaponTime++;
            monsterDefeated++;
        }

        return monsterDefeated;
    }
};