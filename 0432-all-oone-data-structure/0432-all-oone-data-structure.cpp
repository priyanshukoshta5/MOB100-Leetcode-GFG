class AllOne {
private:
    unordered_map<string, int> data;
    set<pair<int, string>> st;

public:
    AllOne() {
        
    }
    
    void inc(string key) {
        data[key]++;
        st.erase({data[key] - 1, key});
        st.insert({data[key], key});
    }
    
    void dec(string key) {
        data[key]--;
        st.erase({data[key] + 1, key});
        if(data[key] == 0)
            data.erase(key);
        else
            st.insert({data[key], key});
    }
    
    string getMaxKey() {
        if(isEmpty())
            return "";
        pair<int, string> p = *st.rbegin();
        return p.second;
    }
    
    string getMinKey() {
        if(isEmpty())
            return "";
        pair<int, string> p = *st.begin();
        return p.second;
    }

    bool isEmpty(){
        return st.empty();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */