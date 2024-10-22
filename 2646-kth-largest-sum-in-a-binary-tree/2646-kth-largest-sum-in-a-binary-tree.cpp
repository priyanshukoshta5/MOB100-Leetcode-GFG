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
    void dfs(TreeNode *node, int d, vector<long long> &levelSum){
        if(node == nullptr)
            return;
        
        if(levelSum.size() == d)
            levelSum.push_back(0);
        levelSum[d] += node->val;

        dfs(node->left, d + 1, levelSum);
        dfs(node->right, d + 1, levelSum);

        return;
    }

public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levelSum;
        dfs(root, 0, levelSum);
        sort(levelSum.begin(), levelSum.end(), greater<long long> ());
        return (k <= levelSum.size()) ? levelSum[k - 1] : -1;
    }
};