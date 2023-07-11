/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool getPathToTarget(TreeNode* root, TreeNode* target, vector<TreeNode*> &path){
        if(root == nullptr)
            return false;
        
        path.push_back(root);
        
        if(path.back() == target)
            return true;
        
        if(getPathToTarget(root->left, target, path) == true)
            return true;
        if(getPathToTarget(root->right, target, path) == true)
            return true;
        
        path.pop_back();
        
        return false;
    }
    
    void getBelowTarget(TreeNode* target, int k, vector<int> &ans){
        if(target == nullptr)
            return;
        if(k == 0)
        {
            ans.push_back(target->val);
            return;
        }
        getBelowTarget(target->left, k-1, ans);
        getBelowTarget(target->right, k-1, ans);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> pathToTarget;
        getPathToTarget(root, target, pathToTarget);
        
        vector<int> ans;
        int size = pathToTarget.size();
        int len = 0;
        for(int i = size-1; i >= 0; i--)
        {
            // cout<<len<<" "<<pathToTarget[i]->val<<endl;
            if(i != size-1)
            {
                TreeNode* node = pathToTarget[i];
                if(len == k)
                    ans.push_back(node->val);
                else if(node->left != pathToTarget[i+1])
                    getBelowTarget(node->left, k-len-1, ans);
                else
                    getBelowTarget(node->right, k-len-1, ans);
            }
            else
                getBelowTarget(pathToTarget[i], k, ans);
            
            len++;
            if(len > k)
                break;
        }
        
        return ans;
    }
};