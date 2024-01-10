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

// ~ with the help of editorial

class Solution {
private:
    int ans = 0;
    int longestPath(TreeNode *node, int src){
        if(node == nullptr)
            return 0;
        
        int left = longestPath(node->left, src);
        int right = longestPath(node->right, src);

        int temp = 0;
        if(node->val == src)
        {
            ans = max(left, right);
            temp = -1;
        }
        else if(left >= 0 && right >= 0)
        {
            temp = max(left, right) + 1;
        }
        else
        {
            ans = max(ans, abs(left) + abs(right));
            temp = min(left, right) - 1;
        }

        return temp;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        longestPath(root, start);
        return ans;
    }
};