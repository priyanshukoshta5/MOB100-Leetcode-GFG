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
    TreeNode* buildBST(vector<int>& nums, int low, int high){
        if(low > high)
            return nullptr;
        
        int mid = low + (high-low)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildBST(nums, low, mid-1);
        node->right = buildBST(nums, mid+1, high);
        
        return node;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        return buildBST(nums, low, high);
    }
};