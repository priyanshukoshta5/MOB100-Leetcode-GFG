class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(auto i: tasks)
            freq[i]++;
        
        vector<int> arr;
        for(auto x: freq)
            arr.push_back(x.second);
        sort(arr.begin(), arr.end(), greater<int> ());
        
        vector<bool> isVisited(1e6 + 5, false);
        int maxInterval = 0;
        
        int interval = 0;
        while(arr[0] > 0)
        {
            int pos = (interval * (n + 1)) + 1;
            int i = 0;
            while(i < arr.size() && arr[i] > 0)
            {
                if(isVisited[pos] == false)
                {
                    isVisited[pos] = true;
                    arr[i]--;
                    i++;
                }
                else
                    pos++;
            }
            maxInterval = max(maxInterval, pos);
            interval++;
        }

        return maxInterval;
    }
};