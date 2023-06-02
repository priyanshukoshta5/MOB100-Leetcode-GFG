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
    Node* clone(Node* node, unordered_map<Node*, Node*>& copies){
        // If the node is already present in the hashmap, we will use it
        if(copies.find(node) != copies.end())
            return copies[node];

        // Creating a dummy/copy node
        Node* newNode = new Node(node->val);
        copies[node] = newNode;

        // Marking all neighbors
        for(auto it: node->neighbors)
            newNode->neighbors.push_back(clone(it, copies));

        return newNode;
    }

public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        
        unordered_map<Node*, Node*> copies; // to store {original,copy}
        return clone(node, copies);;
    }
};