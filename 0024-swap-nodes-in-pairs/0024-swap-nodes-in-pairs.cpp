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
    ListNode* swapPairs(ListNode* head) {
        vector<ListNode*> arr;
        ListNode *temp = head;
        while(temp != nullptr)
        {
            arr.push_back(temp);
            temp = temp->next;
        }

        for(int i=1; i<arr.size(); i+=2)
        {
            temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
        }

        ListNode *newHead = new ListNode(-1);
        temp = newHead;

        for(auto x: arr)
        {
            temp->next = x;
            temp = temp->next;
        }
        temp->next = nullptr;

        return newHead->next;
    }
};