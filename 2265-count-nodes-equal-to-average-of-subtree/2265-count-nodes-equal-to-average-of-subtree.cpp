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

struct Result{
    int total, nodes, ansNodes;
    Result(int t, int n, int a){
        total = t;
        nodes = n;
        ansNodes = a;
    }
};

class Solution {
private:
    Result dfs(TreeNode *node){
        if(node == nullptr)
            return Result(0, 0, 0);

        Result left = dfs(node->left);
        Result right = dfs(node->right);

        Result cur = Result(left.total + right.total + node->val, 
                            left.nodes + right.nodes + 1, 
                            left.ansNodes + right.ansNodes);

        cur.ansNodes += (node->val == (cur.total / cur.nodes));

        return cur;
    }

public:
    int averageOfSubtree(TreeNode* root) {
        return dfs(root).ansNodes;
    }
};