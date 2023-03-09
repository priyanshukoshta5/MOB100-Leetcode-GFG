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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                ListNode *pos = head;
                while(pos != slow)
                {
                    pos = pos->next;
                    slow = slow->next;
                }
                return pos;
            }
        }
        
        return nullptr;
    }
};