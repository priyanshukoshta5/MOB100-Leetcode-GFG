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
    void inOrder(TreeNode* node, vector<int>& arr){
        if(node == nullptr)
            return;
        inOrder(node->left, arr);
        arr.push_back(node->val);
        inOrder(node->right, arr);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inOrder(root, arr);
        int i = 0, j = arr.size()-1;
        while(i < j)
        {
            int sum = arr[i] + arr[j];
            if(sum == k)
                return true;
            else if(sum < k)
                i++;
            else
                j--;
        }
        return false;
    }
};