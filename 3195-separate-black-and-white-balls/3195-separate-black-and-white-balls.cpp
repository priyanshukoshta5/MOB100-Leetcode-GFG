class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        
        long long ops = 0;
        
        // j = white, i = black 
        stack<int> black;
        priority_queue<int> white;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
                black.push(i);
            else
                white.push(i);
        }
        
        while(!black.empty() && !white.empty())
        {
            while(!black.empty() && !white.empty() && black.top() >= white.top())
                black.pop();
            
            if(black.empty() || white.empty())
                break;
            
            long long int w = white.top();
            white.pop();
            long long int b = black.top();
            black.pop();
            
            // cout<<b<<" "<<w<<endl;
            swap(s[w], s[b]);
            white.push(b);
            ops += (w - b);
        }
        // cout<<s<<endl;
        
        return ops;
    }
};