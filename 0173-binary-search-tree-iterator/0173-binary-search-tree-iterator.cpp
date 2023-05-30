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
class BSTIterator {
private:
    stack<TreeNode*> stk;
    
public:
    BSTIterator(TreeNode* root) {
        stk.push(root);
        pushAll(stk);
    }
    
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        if(node->right != nullptr)
        {
            stk.push(node->right);
            pushAll(stk);
        }
        return node->val;
    }
    
    bool hasNext() {
        return stk.size() > 0;
    }
    
    void pushAll(stack<TreeNode*> &stk){
        while(stk.top()->left != nullptr)
            stk.push(stk.top()->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */