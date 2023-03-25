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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ListNode *dummy = new ListNode(); 
        // ListNode *temp = dummy; 
        // int carry = 0;
        // while( (l1 != NULL || l2 != NULL) || carry) {
        //     int sum = 0; 
        //     if(l1 != NULL) {
        //         sum += l1->val; 
        //         l1 = l1 -> next; 
        //     }
            
        //     if(l2 != NULL) {
        //         sum += l2 -> val; 
        //         l2 = l2 -> next; 
        //     }
            
        //     sum += carry; 
        //     carry = sum / 10; 
        //     ListNode *node = new ListNode(sum % 10); 
        //     temp -> next = node; 
        //     temp = temp -> next; 
        // }
        // return dummy -> next; 

        // if(l1 == nullptr)   return l2;
        // if(l2 == nullptr)   return l1;

        ListNode *start = l1;
        ListNode *prev_l1 = nullptr;
        int carry = 0;
        int sum = 0;
        while(l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            l1->val = sum%10;
            carry = sum/10;
            prev_l1 = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1 == nullptr)
            prev_l1->next = l2;
        l1 = prev_l1->next;

        while(l1)
        {
            sum = l1->val + carry;
            l1->val = sum%10;
            carry = sum/10;
            prev_l1 = l1;
            l1 = l1->next;
        }
        if(carry == 1)
            prev_l1->next = new ListNode(1);

        return start;
    }
};