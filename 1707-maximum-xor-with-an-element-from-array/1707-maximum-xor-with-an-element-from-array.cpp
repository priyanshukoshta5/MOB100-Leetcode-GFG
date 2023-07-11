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

class Trie{
private:
    Node *root;

public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node *cur = root;
        for(int i = 31; i >= 0; i--)
        {
            int val = (num >> i) & 1;
            if(!cur->isPresent(val))
                cur->setNode(val, new Node());
            cur = cur->getNext(val);
        }
    }

    int getMax(int num){
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
        return res;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> query;
        for(int i = 0; i < queries.size(); i++)
            query.push_back({queries[i][1], queries[i][0], i});
        sort(query.begin(), query.end());

        Trie trie;

        vector<int> ans(query.size(), -1);
        int i = 0;
        for(auto q: query)
        {
            int m = q[0];
            int num = q[1];
            int ind = q[2];

            while(i < nums.size() && nums[i] <= m)
                trie.insert(nums[i++]);

            if(i != 0)
                ans[ind] = trie.getMax(num);
        }

        return ans;
    }
};