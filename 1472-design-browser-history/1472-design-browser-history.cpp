class BrowserHistory {
private:
    vector<string> sites;
    int start, cur, end;

public:
    BrowserHistory(string homepage) {
        sites.push_back(homepage);
        start = 0; 
        cur = 0;
        end = 0;
    }
    
    void visit(string url) {
        if(sites.size() == (cur+1))
        {
            sites.push_back(url);
            cur++;
        }
        else
        {
            cur++;
            sites[cur] = url;
        }
        end = cur;
        for(string s: sites) cout<<s<<" "; cout<<endl;
    }
    
    string back(int steps) {
        cur = max(start, cur-steps);
        return sites[cur];
    }
    
    string forward(int steps) {
        cur = min(end, cur+steps);
        return sites[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */