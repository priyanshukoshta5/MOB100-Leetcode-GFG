/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    Node* solve(Node* node, unordered_map<Node*, Node*>& mp)
    {
        if(node == nullptr)
            return node;

        if(mp.find(node) != mp.end())
            return mp[node];

        Node* temp = new Node(node->val);
        mp[node] = temp;

        if(node->next != nullptr)
            temp->next = solve(node->next, mp);
        if(node->random != nullptr)
            temp->random = solve(node->random, mp);

        return temp;
    }

public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        return solve(head, mp);
    }
};