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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        ListNode *ptr = newHead;
        ListNode *prev = head;
        while(prev->next != nullptr)
        {
            int sum = 0;
            ListNode *next = prev->next;
            while(next->val != 0)
            {
                sum += next->val;
                next = next->next;
            }
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
            prev = next;
        }
        return newHead->next;
    }
};