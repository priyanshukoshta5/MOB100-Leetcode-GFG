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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        vector<ListNode*> arr;
        for(ListNode* cur = head; cur != nullptr; cur = cur->next)
            arr.push_back(cur);
        
        for(int i = 1; i < arr.size(); i++)
        {
            ListNode* node = new ListNode(__gcd(arr[i-1]->val, arr[i]->val));
            arr[i-1]->next = node;
            node->next = arr[i];
        }
        
        return arr[0];
    }
};