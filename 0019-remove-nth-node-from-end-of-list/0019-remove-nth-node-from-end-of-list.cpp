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
        // Time Complexity - O(n) Single traversal solution.
        
        // taking this instead of directly returning head, to avoid the edge case of n == len(Linked List)
        ListNode *start = new ListNode();
        start->next = head;         
        ListNode *slow = start;
        ListNode *fast = start;
        
        // Creating distance 'n' between the 2 points
        for(int i=1; i<=n; i++)
            fast = fast->next;
        
        // Once we reach 'n' distance between the 2 pointers, we will only move 1-1 step till end.
        while(fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Deleting 'slow->next' node
        slow->next = slow->next->next;
        
        return start->next;
    }
};


/*
    My Solution - TC-O(2n)
    
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
*/