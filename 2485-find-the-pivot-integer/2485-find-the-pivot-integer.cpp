class Solution {
public:
    int pivotInteger(int n) {
        int left = 0;
        int right = (n * (n + 1)) / 2;
        int i = 1;
        while(left < right)
        {
            left += i;
            // cout<<i<<" "<<left<<" "<<right<<endl;
            if(left == right)
                return i;
            right -= i;
            i++;
        }
        return -1;
    }
};