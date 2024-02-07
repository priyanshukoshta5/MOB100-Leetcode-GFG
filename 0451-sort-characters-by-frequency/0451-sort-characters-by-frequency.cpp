class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, int> freq;
        for(char ch: s)
            freq[ch]++;

        priority_queue<pair<int, char>> maxH;
        for(auto x: freq)
            maxH.push({x.second, x.first});
        
        string ans = "";
        while(!maxH.empty())
        {
            auto it = maxH.top();   maxH.pop();
            int cnt = it.first;
            int ch = it.second;
            while(cnt--)
                ans.push_back(ch);
        }

        return ans;
    }
};