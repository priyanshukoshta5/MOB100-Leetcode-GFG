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
private:
    ListNode* reverseLL(ListNode *root){
        ListNode *prev = nullptr;
        ListNode *curr = root;

        while(curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return;

        // step 1: divide list into 2 halfs
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *firstHalf = head;
        ListNode *secondHalf = slow->next;
        slow->next = nullptr;

        // step 2: reverse the second half of the list
        secondHalf = reverseLL(secondHalf);

        // step 3: merge the 2 halfs as per the problem statement
        ListNode *newHead = new ListNode(0);
        ListNode *ptr = newHead;
        while(secondHalf != nullptr)
        {
            ptr->next = firstHalf;
            firstHalf = firstHalf->next;
            ptr = ptr->next;

            ptr->next = secondHalf;
            secondHalf = secondHalf->next;
            ptr = ptr->next;
        }

        if(firstHalf != nullptr)        // if more elements in firstHalf;
            ptr->next = firstHalf;      
    }
};