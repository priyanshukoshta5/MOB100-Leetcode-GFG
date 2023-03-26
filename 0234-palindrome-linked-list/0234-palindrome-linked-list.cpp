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
    ListNode* reverseit(ListNode* node) {
        ListNode* prev=nullptr;
        ListNode* nxt=nullptr;
        while(node!=NULL) {
            nxt = node->next;
            node->next = prev;
            prev = node;
            node = nxt;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseit(slow->next);
        fast = slow->next;
        slow = head;

        while(fast != nullptr)
        {
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
};