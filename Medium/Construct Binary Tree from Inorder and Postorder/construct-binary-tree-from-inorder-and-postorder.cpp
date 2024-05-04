//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    private:
    Node *buildTree(int i, int j, int p, int in[], int post[], map<int, int> &mp){
        if(i > j)
            return nullptr;
        if(i == j)
            return new Node(post[p]);
        
        Node *node = new Node(post[p]);
        int t = mp[post[p]];
        int r = j - t;
        // cout<<t<<" "<<r<<" "<<(p - r - 1)<<" "<<(p - 1)<<endl;
        
        node->left = buildTree(i, t - 1, p - r - 1, in, post, mp);
        node->right = buildTree(t + 1, j, p - 1, in, post, mp);
        
        return node;
    }
    
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[in[i]] = i;
        
        return buildTree(0, n - 1, n - 1, in, post, mp);
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends