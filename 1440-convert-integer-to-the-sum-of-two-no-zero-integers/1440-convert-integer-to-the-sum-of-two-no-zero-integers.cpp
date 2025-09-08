class Solution {
private:
    bool containsZero(int num){
        string s = to_string(num);
        return count(s.begin(), s.end(), '0') > 0;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i <= n/2; i++){
            if(containsZero(i) || containsZero(n - i))
                continue;
            return {i, n - i};
        }
        return {};
    }
};