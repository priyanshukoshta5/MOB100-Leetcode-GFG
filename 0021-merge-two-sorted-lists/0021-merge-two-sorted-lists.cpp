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
        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;
        
        ListNode *newHead = new ListNode();
        ListNode *prev1 = newHead;
        ListNode *cur1 = list1;
        ListNode *cur2 = list2;
        ListNode *next2 = list2->next;
        prev1->next = cur1;
        
        while(cur1 && cur2)
        {
            // If List1->val <= List2->val, Do nothing just move
            if(cur1->val <= cur2->val)  
            {
                prev1 = cur1;
                cur1 = cur1->next;
            }
            // If List1->val > List2->val, insert the node of list2 in list1
            else
            {
                prev1->next = cur2;
                cur2->next = cur1;
                
                prev1 = prev1->next;
                cur2 = next2;
                if(next2 != nullptr)
                    next2 = cur2->next;
            }
        }
        if(cur1 == nullptr)
            prev1->next = cur2;
        
        newHead = newHead->next;
        return newHead;
    }
};