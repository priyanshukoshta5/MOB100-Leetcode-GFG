//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
    void dfs(Node *node, unordered_map<int, vector<int>> &adj){
        if(node == nullptr)
            return;
        
        if(node->left != nullptr)
        {
            adj[node->data].push_back(node->left->data);
            adj[node->left->data].push_back(node->data);
            dfs(node->left, adj);
        }
        
        if(node->right != nullptr)
        {
            adj[node->data].push_back(node->right->data);
            adj[node->right->data].push_back(node->data);
            dfs(node->right, adj);
        }
    }

public:
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // converting tree into graph
        unordered_map<int, vector<int>> adj;
        dfs(root, adj);
        
        vector<int> ans;
        if(adj.find(target) == adj.end())   // target node not present
            return ans;
        
        // applying bfs to find all nodes at a distance k
        queue<pair<int, int>> q;    // {node, parent}
        q.push({target, -1});
        int dist = 0;
        while(!q.empty())
        {
            int size = q.size();
            
            while(size--)
            {
                auto it = q.front();
                q.pop();
                int node = it.first;
                int parent = it.second;
                
                if(dist == k)
                {
                    ans.push_back(node);
                }
                else
                {
                    for(auto x: adj[node])
                    {
                        if(x != parent)
                            q.push({x, node});
                    }
                }
            }
            
            dist++;
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends