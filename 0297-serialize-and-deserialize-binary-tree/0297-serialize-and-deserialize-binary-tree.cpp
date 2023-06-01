/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "";

        string serial;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int len = q.size();
            TreeNode* node = q.front();
            q.pop();
            if(node == nullptr) 
                serial = serial.append("#,");
            else 
            {
                serial.append(to_string(node->val) + ',');
                q.push(node->left);
                q.push(node->right);
            }
            
        }
        
//         cout<<serial<<endl;
        
//         // Removing trainling null values
//         int len = serial.length()-1;
//         while(len > 0 && serial[len-1] == '#')
//         {
//             serial.pop_back();
//             serial.pop_back();
//             len -= 2;
//         }
        
//         cout<<serial<<endl;

        return serial;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0)
            return nullptr;

        stringstream s(data);
        string str;

        // getline will give elements after commas ',' one by one, whenever called and store in string str.
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#")
                node->left = nullptr;
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#")
                node->right = nullptr;
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));