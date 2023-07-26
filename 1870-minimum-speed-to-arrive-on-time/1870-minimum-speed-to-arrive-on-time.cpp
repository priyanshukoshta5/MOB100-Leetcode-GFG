class Solution {
private:
    bool isValid(vector<int> &dist, int speed, double hour){
        double totalTime = 0;

        for(auto d: dist)
        {
            totalTime = ceil(totalTime);
            double curTime = double(d) / double(speed);
            totalTime += curTime;
            if(totalTime > hour)
                return false;
        }
        
        return true;
    }

public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int minSpeed = 1;
        int maxSpeed = 1e9;

        int ansSpeed = -1;
        while(minSpeed <= maxSpeed)
        {
            int mid = minSpeed + (maxSpeed - minSpeed)/2;
            if(isValid(dist, mid, hour))
            {
                ansSpeed = mid;
                maxSpeed = mid - 1;
            }
            else
                minSpeed = mid + 1;
        }

        return ansSpeed;
    }
};