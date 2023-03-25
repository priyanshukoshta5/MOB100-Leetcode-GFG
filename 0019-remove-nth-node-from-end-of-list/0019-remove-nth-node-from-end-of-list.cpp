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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *temp = head;
        while(temp)
        {
            temp = temp->next;
            len++;
        }

        if(n > len)
            return head;
        if(n == len)
            return head->next;

        len = len-n;
        ListNode *prev = nullptr;
        temp = head;
        while(len > 0)
        {
            prev = temp;
            temp = temp->next;
            len--;
        }
        prev->next = temp->next;

        return head;
    }
};