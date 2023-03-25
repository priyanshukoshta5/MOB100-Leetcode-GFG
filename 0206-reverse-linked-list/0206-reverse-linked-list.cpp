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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *nxt = head->next;
        
        while(nxt != nullptr)
        {
            cur->next = prev;
            prev = cur;
            cur = nxt;
            nxt = nxt->next;
        }
        cur->next = prev;
        head = cur;
        
        return head;
    }
};