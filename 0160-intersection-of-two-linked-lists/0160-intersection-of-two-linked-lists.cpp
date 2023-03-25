/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode *h1 = headA;
        ListNode *h2 = headB;
        while(h1 != nullptr)
        {
            len1++;
            h1 = h1->next;
        }
        while(h2 != nullptr)
        {
            len2++;
            h2 = h2->next;
        }
        
        int diff = abs(len1 - len2);
        h1 = headA;
        h2 = headB;
        while(len1 > len2)
        {
            h1 = h1->next;
            len1--;
        }
        while(len1 < len2)
        {
            h2 = h2->next;
            len2--;
        }
        
        while(h1 != h2)
        {
            h1 = h1->next;
            h2 = h2->next;
        }
        
        return h1;
    }
};