//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

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

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
  private:
    int MOD = 1e9+7;
  
    long long int dfs(Node *node, int curSum, int k, unordered_map<int, int> &pathSum){
        if(node == nullptr)
            return 0;
            
        int val = curSum + node->data;
        // cout<<val<<" "<<k - val<<endl;
        long long ans = 0;
        if(pathSum.find(val - k) != pathSum.end())
            ans = pathSum[val - k];
        // cout<<ans<<endl;
        
        pathSum[val]++;
        
        long long int left = dfs(node->left, curSum + node->data, k, pathSum);
        long long int right = dfs(node->right, curSum + node->data, k, pathSum);
        
        pathSum[val]--;
        if(pathSum[val] == 0)
            pathSum.erase(val);
        
        return (ans + left + right) % MOD;
    }
  public:
    int sumK(Node *root, int k)
    {
        unordered_map<int, int> pathSum;
        pathSum[0] = 1;
        return dfs(root, 0, k, pathSum);
    }
};

//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
  
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends