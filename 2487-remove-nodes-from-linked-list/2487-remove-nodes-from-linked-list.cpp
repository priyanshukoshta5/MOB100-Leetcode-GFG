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
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode *newHead = new ListNode(1e6, head);

        stack<ListNode*> stk;
        stk.push(newHead);
        
        ListNode *cur = head;
        while(cur != nullptr)
        {
            while(stk.top()->val < cur->val)
            {
                stk.pop();
                stk.top()->next = cur;
            }
            stk.push(cur);
            cur = cur->next;
        }

        return newHead->next;
    }
};