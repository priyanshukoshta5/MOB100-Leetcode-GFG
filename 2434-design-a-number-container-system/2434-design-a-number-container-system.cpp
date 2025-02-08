class NumberContainers {
private:
    map<int, int> indexNumber;
    map<int, set<int>> numberIndex;

public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexNumber.find(index) == indexNumber.end())
        {
            indexNumber[index] = number;
            numberIndex[number].insert(index);
        }
        else
        {
            int num = indexNumber[index];
            numberIndex[num].erase(index);

            indexNumber[index] = number;
            numberIndex[number].insert(index);
        }
    }
    
    int find(int number) {
        if(numberIndex.find(number) != numberIndex.end() && numberIndex[number].size() > 0)
            return *numberIndex[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */