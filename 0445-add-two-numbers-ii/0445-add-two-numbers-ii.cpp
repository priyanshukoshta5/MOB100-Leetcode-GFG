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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode *> stk1, stk2;
        
        for(auto cur = l1; cur != nullptr; cur = cur->next)
            stk1.push(cur);
        
        for(auto cur = l2; cur != nullptr; cur = cur->next)
            stk2.push(cur);

        ListNode* newHead = nullptr;
        int rem = 0;
        while(!stk1.empty() || !stk2.empty() || rem != 0)
        {
            int val = rem;
            if(!stk1.empty())
            {
                val += stk1.top()->val;
                stk1.pop();
            }
            if(!stk2.empty())
            {
                val += stk2.top()->val;
                stk2.pop();
            }
            ListNode* node = new ListNode(val % 10);
            rem = val / 10;
            node->next = newHead;
            newHead = node;
        }

        return newHead;
    }
};