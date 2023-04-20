//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

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
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{
    private:
    
    void getLadoo(Node* node, Node* src, int reach, int& ans, unordered_map<Node*, Node*>& mp){
        if(node == nullptr)
            return;
            
        if(reach < 0)
            return;
            
        ans += node->data;
        
        if(mp[node] != src)
            getLadoo(mp[node], node, reach-1, ans, mp);      // Going to parent
        if(node->left != src) 
            getLadoo(node->left, node, reach-1, ans, mp);
        if(node->right != src)
            getLadoo(node->right, node, reach-1, ans, mp);
        
    }
    
    void findAndBack(Node* node, Node* parent, int home, int& reach, int &ans, unordered_map<Node*, Node*>& mp){
        if(node == nullptr)
            return;
        
        mp[node] = parent;
        
        if(node->data == home)
        {
            getLadoo(node, nullptr, reach, ans, mp);
            return;
        }
        
        findAndBack(node->left, node, home, reach, ans, mp);
        findAndBack(node->right, node, home, reach, ans, mp);
    }

    public:
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        
        int ans = 0;
        int reach = k;
        unordered_map<Node*, Node*> mp;
        findAndBack(root, nullptr, home, reach, ans, mp);
        
        return ans;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends