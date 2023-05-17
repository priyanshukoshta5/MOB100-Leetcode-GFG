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
        vector<int> vals;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            vals.push_back(temp->val);
            vals.push_back(temp->next->val);
            temp = temp->next->next;
        }
        
        int ans = INT_MIN;
        for(int i=0, j=vals.size()-1; i<j; i++, j--)
            ans = max(ans, vals[i]+vals[j]);
        
        return ans;
    }
};