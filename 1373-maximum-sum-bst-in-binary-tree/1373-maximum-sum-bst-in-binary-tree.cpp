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

class NodeValue{
public:
    int minVal, maxVal, maxSum;

    NodeValue(int mini, int maxi, int sum){
        minVal = mini;
        maxVal = maxi;
        maxSum = sum;
    }
};

class Solution {
public:
    NodeValue solve(TreeNode* node, int& ans){
        if(node == nullptr)
            return NodeValue(INT_MAX, INT_MIN, 0);

        NodeValue left = solve(node->left, ans);
        NodeValue right = solve(node->right, ans);

        // cout<<node->val<<endl;
        // cout<<left.minVal<<" "<<left.maxVal<<" "<<left.maxSum<<endl;
        // cout<<right.minVal<<" "<<right.maxVal<<" "<<right.maxSum<<endl;
        // cout<<"VALID : "<<(left.maxVal < node->val && node->val < right.minVal)<<endl;
        // cout<<endl;

        // If valid BST
        if(left.maxVal < node->val && node->val < right.minVal)
        {
            ans = max(ans, left.maxSum + right.maxSum + node->val);
            return NodeValue(min(node->val, left.minVal), 
                             max(node->val, right.maxVal), 
                             left.maxSum + right.maxSum + node->val);
        }

        // If not valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};