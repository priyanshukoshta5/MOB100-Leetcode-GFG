struct Node{
    Node *links[2];

    bool isPresent(int val){
        return links[val] != nullptr;
    }
    void setNode(int val, Node *node){
        links[val] = node;
    }
    Node *getNext(int val){
        return links[val];
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node *root = new Node();

        for(int num: nums)
        {
            Node *cur = root;
            for(int i = 31; i >= 0; i--)
            {
                int val = (num >> i) & 1;
                if(!cur->isPresent(val))
                    cur->setNode(val, new Node());
                cur = cur->getNext(val);
            }
        }

        int ans = 0;
        for(int num: nums)
        {
            Node *cur = root;
            int res = 0;
            for(int i = 31; i >= 0; i--)
            {
                int val = (num >> i) & 1;
                if(cur->isPresent( !val ))
                {
                    cur = cur->getNext(!val);
                    res += (1 << i);
                }
                else
                {
                    cur = cur->getNext(val);
                }
            }
            ans = max(ans, res);
        }

        return ans;
    }
};