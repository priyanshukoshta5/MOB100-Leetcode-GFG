class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        if(limit < people.back())
            return -1;
        
        int i = 0, j = people.size() - 1;
        int boats = 0;
        while(i <= j)
        {
            boats++;
            if((people[i] + people[j]) <= limit)
                i++;
            j--;
        }
        
        return boats;
    }
};