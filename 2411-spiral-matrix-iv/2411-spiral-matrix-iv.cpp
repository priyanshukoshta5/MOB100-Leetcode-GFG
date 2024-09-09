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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        if(m == 1 && n == 1)
        {
            if(head == nullptr)
                return {{-1}};
            return {{head->val}};
        }

        vector<vector<int>> matrix(m, vector<int> (n, -1));
        ListNode *ptr = head;
        int spiral = 0;
        int x = 0, y = 0;
        while(true)
        {
            x = y = spiral;

            // left to right
            for(int i = spiral; i < n - spiral - 1 && ptr != nullptr; i++)
            {
                matrix[x][y] = ptr->val;
                ptr = ptr->next;
                y++;
            }

            // top to bottom
            for(int j = spiral; j < m - spiral - 1 && ptr != nullptr; j++)
            {
                matrix[x][y] = ptr->val;
                ptr = ptr->next;
                x++;
            }

            // right to left
            for(int i = n - spiral - 1; i > spiral && ptr != nullptr; i--)
            {
                matrix[x][y] = ptr->val;
                ptr = ptr->next;
                y--;
            }

            // bottom to top
            for(int j = m - spiral - 1; j > spiral && ptr != nullptr; j--)
            {
                matrix[x][y] = ptr->val;
                ptr = ptr->next;
                x--;
            }

            spiral++;
            
            if(ptr == nullptr || ptr->next == nullptr)
                break;
        }

        if(ptr != nullptr)
            matrix[spiral][spiral] = ptr->val;

        return matrix;
    }
};