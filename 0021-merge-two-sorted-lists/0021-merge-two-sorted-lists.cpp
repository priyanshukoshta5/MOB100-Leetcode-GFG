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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newHead = new ListNode();
        ListNode *cur = newHead;
        ListNode *ll1 = list1;
        ListNode *ll2 = list2;
        
        while(ll1 && ll2)
        {
            if(ll1->val <= ll2->val)
            {
                cur->next = new ListNode(ll1->val);
                cur = cur->next;
                ll1 = ll1->next;
            }
            else
            {
                cur->next = new ListNode(ll2->val);
                cur = cur->next;
                ll2 = ll2->next;
            }
        }
        while(ll1)
        {
            cur->next = new ListNode(ll1->val);
            cur = cur->next;
            ll1 = ll1->next;
        }
        while(ll2)
        {
            cur->next = new ListNode(ll2->val);
            cur = cur->next;
            ll2 = ll2->next;
        }
        
        newHead = newHead->next;
        return newHead;
    }
};