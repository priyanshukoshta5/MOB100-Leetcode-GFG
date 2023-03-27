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

class Solution {public:
    Node* copyRandomList(Node* head) {
        // Thanks to Striver.

        // Step 1 -
        Node* iter = head;
        Node* front = head;
        Node* copy;
        while(iter != nullptr)
        {
            front = iter->next;
            copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }

        // Step 2 - 
        iter = head;
        while(iter != nullptr)
        {
            if(iter->random != nullptr)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }

        // Step 3 - 
        iter = head;
        Node* pseudonode = new Node(0);
        copy = pseudonode;
        while(iter != nullptr)
        {
            front = iter->next->next;
            copy->next = iter->next;
            copy = copy->next;
            iter->next = front;
            iter = iter->next;
        }

        return pseudonode->next;
    }
};