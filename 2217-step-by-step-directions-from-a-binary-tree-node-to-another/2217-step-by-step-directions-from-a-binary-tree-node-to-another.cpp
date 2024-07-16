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
    bool flag = false;

    void dfs(TreeNode* root, int x, string &path){
        if(root == nullptr || flag == true)
            return;
        if(root->val == x)
        {
            flag = true;
            return;
        }
        if(flag == false)
        {
            path.push_back('L');
            dfs(root->left, x, path);
            if(flag == true)
                return;
            path.pop_back();
        }
        if(flag == false)
        {
            path.push_back('R');
            dfs(root->right, x, path);
            if(flag == true)
                return;
            path.pop_back();
        }
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToStart = "";
        flag = false;
        dfs(root, startValue, rootToStart);

        string rootToDest = "";
        flag = false;
        dfs(root, destValue, rootToDest);

        string ans = "";
        int i = 0, j = 0;
        while(i < rootToStart.length() && j < rootToDest.length() && rootToStart[i] == rootToDest[j])
        {
            i++;
            j++;
        }
        for(; i < rootToStart.length(); i++)
            ans.push_back('U');
        for(; j < rootToDest.length(); j++)
            ans.push_back(rootToDest[j]);
        
        return ans;
    }
};