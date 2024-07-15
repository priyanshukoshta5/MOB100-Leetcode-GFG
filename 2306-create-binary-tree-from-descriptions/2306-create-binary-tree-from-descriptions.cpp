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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, TreeNode*> mp;
        map<int, bool> isRoot;
        for(auto x: descriptions)
        {
            int par = x[0];
            int chi = x[1];
            int isLeft = x[2];

            TreeNode *parent = nullptr;
            if(mp.find(par) == mp.end())
            {
                parent = new TreeNode(par);
                mp[par] = parent;
                isRoot[par] = true;
            }
            else
            {
                parent = mp[par];
                isRoot[chi] &= true;
            }

            TreeNode *child = nullptr;
            if(mp.find(chi) == mp.end())
            {
                child = new TreeNode(chi);
                mp[chi] = child;
                isRoot[chi] = false;
            }
            else
            {
                child = mp[chi];
                isRoot[chi] &= false;
            }
            
            if(isLeft == 1)
                parent->left = child;
            else
                parent->right = child;
        }

        int root = -1;
        for(auto x: isRoot)
        {
            if(x.second == true)
            {
                root = x.first;
                break;
            }
        }

        return mp[root];
    }
};