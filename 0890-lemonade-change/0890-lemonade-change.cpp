class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int _5 = 0, _10 = 0, _20 = 0;
        for(int i: bills)
        {
            if(i == 5)
            {
                _5++;
            }
            else if(i == 10)
            {
                if(_5 > 0)
                    _5--;
                else
                    return false;
                _10++;
            }
            else if(i == 20)
            {
                if(_10 > 0 && _5 > 0)
                {
                    _10--;
                    _5--;
                }
                else if(_5 >= 3)
                {
                    _5 -= 3;
                }
                else
                    return false;
                _20++;
            }
            else 
                return false;
        }
        return true;
    }
};