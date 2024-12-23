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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);

        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();

            vector<int> nodes;
            while(size--)
            {
                TreeNode *node = q.front();
                q.pop();

                nodes.push_back(node->val);

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

            vector<int> real = nodes;
            sort(real.begin(), real.end());

            unordered_map<int, int> pos;
            for(int i = 0; i < nodes.size(); i++)
                pos[nodes[i]] = i;

            int swaps = 0;
            for(int i = 0; i < nodes.size(); i++) 
            {
                if (nodes[i] != real[i]) 
                {
                    swaps++;

                    int curPos = pos[real[i]];
                    pos[nodes[i]] = curPos;
                    swap(nodes[curPos], nodes[i]);
                }
            }

            ans += swaps;
        }

        return ans;
    }
};