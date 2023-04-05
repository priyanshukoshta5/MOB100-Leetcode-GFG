class MedianFinder {
public:
    priority_queue<int> maxH; // to store the left part
    priority_queue<int, vector<int>, greater<int>> minH; // to store the right part
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxH.push(num);

        // make sure every element in left(maxH) <= every element in right(minH)
        if(!maxH.empty() && !minH.empty() && maxH.top() > minH.top())
        {
            minH.push(maxH.top());
            maxH.pop();
        }

        // uneven size handling
        if(maxH.size() > minH.size()+1)
        {
            minH.push(maxH.top());
            maxH.pop();
        }
        if(minH.size() > maxH.size()+1)
        {
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if(maxH.size() > minH.size())
            return maxH.top();
        if(maxH.size() < minH.size())
            return minH.top();

        return (maxH.top() + minH.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */