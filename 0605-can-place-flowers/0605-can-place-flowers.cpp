class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
            return true;
        int len = flowerbed.size();
        if(n > len)
            return false;
        if(len == 1)
        {
            if(n==1 && flowerbed[0]==0)
                return true;
            return false;
        }

        int i = 0;
        while(i<len && n>0)
        {
            if(i == 0)
            {
                if(flowerbed[i] == 0 && flowerbed[i+1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else if(i == len-1)
            {
                if(flowerbed[i-1] == 0 && flowerbed[i] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            else
            {
                if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
            i++;
        }

        if(n == 0)
            return true;
        return false;
    }
};