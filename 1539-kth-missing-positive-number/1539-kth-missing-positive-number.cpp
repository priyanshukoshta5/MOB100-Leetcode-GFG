class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=1, j=0;
        while(j<arr.size() && k>0)
        {
            if(arr[j] == i)
                j++;
            else
                k--;
            i++;
        }
        while(k>0)
        {
            i++;
            k--;
        }
        return i-1;
    }
};