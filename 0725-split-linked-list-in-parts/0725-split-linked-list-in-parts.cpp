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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        for(auto temp = head; temp != nullptr; temp = temp->next)
            len++;

        int parts = len / k;
        int extra = len % k;
        
        vector<ListNode*> ans(k, nullptr);
        ListNode *cur = head;
        for(int i = 0; i < k; i++)
        {
            int partSize = parts + (extra != 0);

            ans[i] = cur;
            partSize--;
            while(cur != nullptr && partSize > 0)
            {
                cur = cur->next;
                partSize--;
            }
            if(cur == nullptr)
                break;

            ListNode *next = cur->next;
            cur->next = nullptr;
            cur = next;

            extra = max(0, extra - 1);
        }

        return ans;
    }
};