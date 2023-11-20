class Solution {
private:
    int collectGarbage(vector<string>& garbage, vector<int>& travel, char garbageType){
        int total = 0;
        int travelTime = 0;
        for(int i = 0; i < garbage.size(); i++)
        {
            if(i > 0)
                travelTime += travel[i - 1];

            int cnt = 0;
            for(char ch: garbage[i])
            {
                if(ch == garbageType)
                    cnt++;
            }

            if(cnt != 0)
            {
                total = total + cnt + travelTime;
                travelTime = 0;
            }
        }
        return total;
    }

public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pTruck = collectGarbage(garbage, travel, 'P');
        int gTruck = collectGarbage(garbage, travel, 'G');
        int mTruck = collectGarbage(garbage, travel, 'M');
        return (pTruck + mTruck + gTruck);
    }
};