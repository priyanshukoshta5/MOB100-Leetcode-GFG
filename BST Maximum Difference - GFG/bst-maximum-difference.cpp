//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    bool isLeaf(Node* node){
        return node->left == nullptr && node->right == nullptr;
    }

    void getMinSum(Node* node, int diff, int& ans){
        if(node == nullptr)
            return;
            
        if(isLeaf(node))
        {
            ans = max(ans, diff-node->data);
            return;
        }
        
        getMinSum(node->left, diff-node->data, ans);
        getMinSum(node->right, diff-node->data, ans);
    }
    
public:
    int maxDifferenceBST(Node *root,int target){
        Node* temp = root;
        int sum_above = 0;
        while(temp != nullptr && temp->data != target)
        {
            sum_above += temp->data;
            if(target < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        
        if(temp == nullptr)
            return -1;
            
        if(isLeaf(temp))
            return sum_above;
        
        int ans = INT_MIN;
        getMinSum(temp->left, sum_above, ans);
        getMinSum(temp->right, sum_above, ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends