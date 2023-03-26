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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1)
            return head;
        
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *prev=dummy;
        ListNode *cur, *nxt;
    
        int len = 0;
        cur = head;
        while(cur)
        {
            cur = cur->next;
            len++;
        }

        while(len >= k)
        {
            cur = prev->next;
            nxt = cur->next;
            for(int i=1; i<k; i++)
            {
                cur->next = nxt->next;
                nxt->next = prev->next;
                prev->next = nxt;
                nxt = cur->next;
            }
            prev = cur;
            len = len-k;
        }
        
        return dummy->next;
    }
};