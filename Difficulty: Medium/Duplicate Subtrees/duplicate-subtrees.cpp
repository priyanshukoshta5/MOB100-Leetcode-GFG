//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating veactor of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = "";
        currVal += ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void preorder(Node* root, vector<int>& temp) {
    if (!root) {
        return;
    }
    // cout<<root->data<<" ";
    temp.push_back(root->data);
    preorder(root->left, temp);
    preorder(root->right, temp);
}


// } Driver Code Ends

// ~PRIYANSHU SHARMA

class Solution {
  public:
    string serialize(Node* root, unordered_map<string, int>& subtreeMap, vector<Node*>& duplicates) {
        if (root == NULL) return "#";  // Use '#' to represent null nodes

        // Serialize left and right subtrees
        string left = serialize(root->left, subtreeMap, duplicates);
        string right = serialize(root->right, subtreeMap, duplicates);

        // Create the current subtree's serialized string
        string subtree = to_string(root->data) + "," + left + "," + right;

        // Track the frequency of the current subtree
        subtreeMap[subtree]++;

        // If the current subtree is seen exactly twice, add the root to the duplicates
        if (subtreeMap[subtree] == 2) {
            duplicates.push_back(root);
        }

        return subtree;
    }

    vector<Node*> printAllDups(Node* root) {
        vector<Node*> duplicates;
        unordered_map<string, int> subtreeMap;
        serialize(root, subtreeMap, duplicates);
        return duplicates;
    }
};


//{ Driver Code Starts.

int main() {

    int tc;
    cin >> tc;
    while (tc--) {

        string treeString;
        getline(cin >> ws, treeString);

        Node* root = buildTree(treeString);
        Solution obj;
        vector<Node*> res = obj.printAllDups(root);

        vector<vector<int>> ans;

        for (int i = 0; i < res.size(); i++) {
            vector<int> temp;
            preorder(res[i], temp);
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        // cout<<"\n";
    }
    return 0;
}

// } Driver Code Ends