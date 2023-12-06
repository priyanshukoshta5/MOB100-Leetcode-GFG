class Solution {
public:
    int totalMoney(int n) {
        int sum1to7 = 1 + 2 + 3 + 4 + 5 + 6 + 7;
        int total_money = 0;
        int week = 0;
        while(n >= 7)
        {
            total_money += (week * 7) + sum1to7;
            week++;
            n = n - 7;
        }
        total_money += (week * n);
        for(int i = 1; i <= n; i++)
            total_money += i;
        return total_money;
    }
};