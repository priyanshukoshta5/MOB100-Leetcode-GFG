class SmallestInfiniteSet {
private:
    set<int> s;
    int smallest;

public:
    SmallestInfiniteSet() {
        smallest = 1;
    }
    
    int popSmallest() {
        int num;
        if(!s.empty())
        {
            num = *s.begin();
            if(num >= smallest)
            {
                num = smallest;
                smallest++;
            }
            s.erase(num);
        }
        else
        {
            num = smallest;
            smallest++;
        }
        return num;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */