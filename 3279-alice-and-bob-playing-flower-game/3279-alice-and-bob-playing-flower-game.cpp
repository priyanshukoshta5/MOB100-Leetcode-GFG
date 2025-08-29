class Solution {
public:
    long long flowerGame(int n, int m) {
        int oddsInN = ceil(n / 2);
        int evensInN = n - oddsInN;

        int oddsInM = ceil(m / 2);
        int evensInM = m - oddsInM;

        return (1LL * oddsInN * evensInM) + (1LL * evensInN * oddsInM);
    }
};