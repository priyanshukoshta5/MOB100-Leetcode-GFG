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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<ListNode *> arr;
        for(auto i = head; i != nullptr; i = i->next)
            arr.push_back(i);
        arr.push_back(nullptr);
        
        int n = arr.size();
        vector<int> temp(n - 1, -1);
        for(int i = 0; i < n - 1; i++)
        {
            int sum = 0;
            for(int j = i; j < n - 1; j++)
            {
                sum += arr[j]->val;
                if(sum == 0)
                    temp[i] = j;
            }
        }

        ListNode *newHead = new ListNode(0, head);
        ListNode *prev = newHead;
        int i = 0;
        while(i < (n - 1) && arr[i] != nullptr)
        {
            ListNode *cur = arr[i];
            if(temp[i] == -1)
            {
                prev = cur;
                i++;
            }
            else
            {
                prev->next = arr[temp[i] + 1];
                i = temp[i] + 1;
            }
        }

        return newHead->next;
    }
};