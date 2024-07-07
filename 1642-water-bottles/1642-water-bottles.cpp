class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalFull = numBottles;
        int totalEmpty = 0;
        int ans = 0;
        while((totalFull + totalEmpty) >= numExchange)
        {
            ans += totalFull;
            totalEmpty += totalFull;
            totalFull = totalEmpty / numExchange;
            totalEmpty = totalEmpty % numExchange;
        }
        return ans + totalFull;
    }
};