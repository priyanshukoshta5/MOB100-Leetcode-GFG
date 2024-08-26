/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void traverse(Node *root, vector<int> &order){
        if(root == nullptr)
            return;
        
        int size = root->children.size();
        for(int i = 0; i < size; i++)
            traverse(root->children[i], order);
        
        order.push_back(root->val);
        return;
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> order;
        traverse(root, order);
        return order;
    }
};