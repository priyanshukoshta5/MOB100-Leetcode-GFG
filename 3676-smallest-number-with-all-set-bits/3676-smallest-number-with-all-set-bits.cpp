class Solution {
public:
    int smallestNumber(int n) {
        if(n == 1)
            return 1;
        while(true){
            // cout<<ceil(log2(n))<<" "<<__builtin_popcount(n)<<endl;
            if(ceil(log2(n)) == __builtin_popcount(n))
                return n;
            n++;
        }
        return 0;
    }
};