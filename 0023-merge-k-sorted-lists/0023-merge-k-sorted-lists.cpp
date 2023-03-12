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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minH;
        for(ListNode* ll: lists)
        {
            ListNode* temp = ll;
            while(temp != nullptr)
            {
                minH.push(temp->val);
                temp = temp->next;
            }
        }
        
        ListNode* finalList = new ListNode();
        ListNode* temp = finalList;
        while(!minH.empty())
        {
            temp->next = new ListNode(minH.top());
            temp = temp->next;
            minH.pop();
        }

        return finalList->next;
    }
};