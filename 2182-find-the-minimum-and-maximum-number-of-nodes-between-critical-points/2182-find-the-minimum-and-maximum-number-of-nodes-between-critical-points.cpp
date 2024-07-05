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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2, -1);
        if(head->next == nullptr || head->next->next == nullptr)
            return ans;

        int firstCP = -1, prevCP = -1;
        ListNode *prev = head;
        ListNode *cur = head->next;
        int pos = 0;
        while(cur->next != nullptr)
        {
            if((prev->val > cur->val && cur->val < cur->next->val) || 
               (prev->val < cur->val && cur->val > cur->next->val))
            {
                if(firstCP == -1)
                    firstCP = pos;
                    
                else
                {
                    if(ans[0] == -1)
                        ans[0] = pos - prevCP;
                    else
                        ans[0] = min(ans[0], pos - prevCP);
                }
                prevCP = pos;
            }
            prev = prev->next;
            cur = cur->next;
            pos++;
        }
        if(ans[0] != -1)
            ans[1] = prevCP - firstCP;

        return ans;
    }
};