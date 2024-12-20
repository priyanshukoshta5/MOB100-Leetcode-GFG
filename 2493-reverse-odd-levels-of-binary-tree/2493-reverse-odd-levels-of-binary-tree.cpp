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
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        
        queue<TreeNode *> q;
        q.push(root);
        int d = 0;
        while(!q.empty())
        {
            int size = q.size();
            vector<TreeNode *> nodes;
            while(size--)
            {
                TreeNode *node = q.front(); q.pop();
                if(node->left)
                {
                    nodes.push_back(node->left);
                    nodes.push_back(node->right);
                }
            }

            if(d % 2 == 0)      // next level is odd;
            {
                size = nodes.size();
                cout<<size<<endl;
                for(int i = 0, j = size - 1; i < j; i++, j--)
                {
                    int temp = nodes[i]->val;
                    nodes[i]->val = nodes[j]->val;
                    nodes[j]->val = temp;
                }
            }

            for(auto i: nodes)
                q.push(i);

            nodes.clear();
            d++;
        }

        return root;
    }
};