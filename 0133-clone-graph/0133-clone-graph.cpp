/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// Thanks NeetCode.

class Solution {
private:
    unordered_map<Node*, Node*> copies; // to store {original,copy}

public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        
        if(copies.find(node) == copies.end())
        {
            Node* newNode = new Node(node->val);
            copies[node] = newNode;
            for(auto it: node->neighbors)
                newNode->neighbors.push_back(cloneGraph(it));
        }
        
        return copies[node];
    }
};