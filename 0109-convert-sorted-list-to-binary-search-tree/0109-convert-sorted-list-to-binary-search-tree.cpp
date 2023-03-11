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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* makeBST(vector<int>& arr, int low, int high)
    {
        if(low <= high)
        {
            int mid = low + (high-low)/2;
            TreeNode* node = new TreeNode(arr[mid]);
            node->left = makeBST(arr, low, mid-1);
            node->right = makeBST(arr, mid+1, high);
            return node;
        }
        return nullptr;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        return makeBST(nums, 0, nums.size()-1);
    }
};