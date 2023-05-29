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
    TreeNode* buildBST(vector<int>& preorder, int low, int high){
        if(low > high) return nullptr;
        
        TreeNode* node = new TreeNode(preorder[low]);
        
        int mid = low + 1;
        while(mid <= high && preorder[mid] < node->val)
            mid++;
        
        node->left = buildBST(preorder, low+1, mid-1);
        node->right = buildBST(preorder, mid, high);

        return node;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int low = 0, high = preorder.size()-1;
        return buildBST(preorder, low, high);
    }
};