class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0)
            return myPow(1/x, abs(n));
        if(n == 0)
            return 1;
        if(n == 1)
            return x;

        n = abs(n);
        double temp = myPow(x, n/2);
        if(n % 2 == 0)
            return temp * temp;
        else
            return temp * temp * x;
    }
};