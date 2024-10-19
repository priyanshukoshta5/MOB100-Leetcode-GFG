class Solution {
string revInv(string s){
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '1')
            s[i] = '0';
        else
            s[i] = '1';
    }
    reverse(s.begin(), s.end());
    return s;
}

public:
    char findKthBit(int n, int k) {
        string str = "0";
        // cout<<str<<endl;
        for(int i = 1; i < n; i++)
        {
            string right = revInv(str);
            str.push_back('1');
            str.append(right);
            // cout<<str<<endl;
        }
        return str[k - 1];
    }
};