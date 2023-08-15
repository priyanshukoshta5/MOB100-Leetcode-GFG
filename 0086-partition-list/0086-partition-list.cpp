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
    ListNode* partition(ListNode* head, int x) {
        ListNode *part1Head = new ListNode(0), *temp1 = part1Head;
        ListNode *part2Head = new ListNode(0), *temp2 = part2Head;

        for(auto it = head; it != nullptr; it = it->next)
        {
            if(it->val < x)
            {
                temp1->next = it;
                temp1 = temp1->next;
            }
            else
            {
                temp2->next = it;
                temp2 = temp2->next;
            }
        }

        temp1->next = part2Head->next;
        temp2->next = nullptr;

        return part1Head->next;
    }
};