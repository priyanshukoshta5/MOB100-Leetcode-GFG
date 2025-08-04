class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freq;
        int i = 0, j = 0;
        int ans = 0;
        while(j < fruits.size()){
            freq[fruits[j]]++;
            while(i <= j && freq.size() > 2){
                freq[fruits[i]]--;
                if(freq[fruits[i]] == 0)
                    freq.erase(fruits[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};