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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // 1. finding ath node, nodeA will store prev node of ath node
        ListNode *nodeA = list1;
        int pos = 0;
        while(pos < (a - 1))
        {
            nodeA = nodeA->next;
            pos++;
        }

        // 2. finding bth node, nodeB will store Bth node
        ListNode *nodeB = nodeA;
        while(pos < b)
        {
            nodeB = nodeB->next;
            pos++;
        }

        // 3. inserting list2 in nodeA
        nodeA->next = list2;

        // 4. getting to the end of list2
        while(nodeA->next != nullptr)
            nodeA = nodeA->next;
        
        // 5. joining remaining nodes in list1
        nodeA->next = nodeB->next;
        
        return list1;
    }
};