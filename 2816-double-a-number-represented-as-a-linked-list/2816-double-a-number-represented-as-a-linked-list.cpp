/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    int rem = 0;
    void solve(ListNode *node){
        if(node == nullptr)
            return;
        
        solve(node->next);

        int res = node->val * 2 + rem;
        node->val = res % 10;
        rem = res / 10;
    }

public:
    ListNode* doubleIt(ListNode* head) {
        solve(head);
        if(rem != 0)
        {
            ListNode *node = new ListNode(rem, head);
            head = node;
        }
        return head;
    }
};