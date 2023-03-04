class Solution {
public:
    int splitNum(int num) {
        string s;
        while(num>0)
        {
            if(num%10 != 0)
                s.push_back(num%10+'0');
            num /= 10;
        }
        sort(s.begin(), s.end());
        int temp;
        int first = 0, last = 0;
        int i = 0;
        while(i<s.length())
        {
            if(i%2 == 0)
            {
                first *= 10;
                first += (s[i]-'0');
            }
            else
            {
                last *= 10;
                last += (s[i]-'0');
            }
            i++;
        }
        
        return (first+last);
    }
};