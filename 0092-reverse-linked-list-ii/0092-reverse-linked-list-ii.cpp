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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 'newHead' will point to the head of the final LL, even if left = 1
        ListNode *newHead = new ListNode(0, head);
        
        // 'prevHead' will point to the node previous to the node at position = left
        ListNode *prevHead = newHead;
        
        // 'temp' will store the node with position = left
        ListNode *temp = head;
        
        // initial position
        int pos = 1;
        
        // iterating till we reach pos = left
        while(pos < left)
        {
            temp = temp->next;  // go to next node
            prevHead = prevHead->next;  // point prev node of 'temp'
            pos++;              // incrementing position
        }

        // 'revListStart' will store the Start of the LL we need to reverse, further it will point to the start of right part of not reversed list
        ListNode *revListStart = temp;
        
        // 'prev' and 'curr' as standard LL reversing algorithm starting from node = temp = left
        ListNode *prev = nullptr;
        ListNode *curr = temp;
        
        // reversing nodes till we reach the end of LL or we reach position = right
        while(curr != nullptr && pos <= right)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            pos++;
        }

        // changing the next pointer of 'end of left half LL' to 'end of reversed LL'
        prevHead->next = prev;
        
        // changing the next pointer of 'start of reversed LL(actually the end)' to the 'start of right half LL'
        revListStart->next = curr;

        // returning the next node of our newHead
        return newHead->next;
    }
};