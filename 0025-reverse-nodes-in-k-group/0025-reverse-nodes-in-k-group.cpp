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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1 || head->next==NULL)
            return head;
        ListNode *temp, *cur=head, *first;
        temp = new ListNode();
        stack<ListNode*> s;
        bool flag=true;
        while(cur!=NULL)
        {
            s.push(cur);
            cur = cur->next;
            if(s.size()==k)
            {
                while(s.size())
                {
                    temp->next = s.top();
                    s.pop();
                    temp = temp->next;
                    if(flag==true)
                    {
                        first = temp;
                        flag = false;
                    }
                }
                temp->next = cur;
            }
        }
        return first;
    }
};