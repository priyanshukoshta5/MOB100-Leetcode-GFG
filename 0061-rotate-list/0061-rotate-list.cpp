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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0)
            return head;

        int len = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            len++;
            temp = temp->next;
        }
        
        k = k%len;
        k = len-k;
        if(k == len)
            return head;

        temp = head;
        while((k-1) > 0)
        {
            temp = temp->next;
            k--;
        }

        ListNode *nxt = temp->next;
        temp->next = nullptr;
        temp = nxt;

        while(temp->next != nullptr)
            temp = temp->next;
            
        temp->next = head;

        return nxt;
    }
};