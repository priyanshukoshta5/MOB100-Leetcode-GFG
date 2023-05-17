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
    int pairSum(ListNode* head) {
        deque<int> dq;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            dq.push_back(temp->val);
            dq.push_back(temp->next->val);
            temp = temp->next->next;
        }
        
        int ans = INT_MIN;
        while(!dq.empty())
        {
            ans = max(ans, dq.front()+dq.back());
            dq.pop_front();
            dq.pop_back();
        }
        
        return ans;
    }
};