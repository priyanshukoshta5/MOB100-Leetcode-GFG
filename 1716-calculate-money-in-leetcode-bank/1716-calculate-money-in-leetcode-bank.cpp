class Solution {
private:
    int getSumOfNNaturalNumbers(int n){ // for small value of N
        return (n * (n + 1)) / 2;
    }
    int getSumOfAP(int start, int diff, int n){
        return (n * (start + (n - 1) * diff)) / 2;
    }
    
public:
    int totalMoney(int n) {
        int complete_weeks = n / 7;
        int remaining_days = n % 7;
        int total_money = 0;

        // adding money in all the complete weeks 
        total_money += complete_weeks *  getSumOfNNaturalNumbers(7);
        total_money += getSumOfAP(0, 7, complete_weeks);

        // adding money in days left
        total_money += getSumOfNNaturalNumbers(remaining_days);
        total_money += remaining_days * complete_weeks;

        return total_money;
    }
};