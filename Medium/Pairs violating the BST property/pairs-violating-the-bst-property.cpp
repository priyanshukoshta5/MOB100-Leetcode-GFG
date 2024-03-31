//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
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
    Node* root = newNode(stoi(ip[0]));

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
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  private:
    void inOrder(Node *node, vector<int> &arr){
        if(node == nullptr)
            return;
        inOrder(node->left, arr);
        arr.push_back(node->data);
        inOrder(node->right, arr);
    }
    
    int merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp; // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr
    
        //Modification 1: cnt variable to count the pairs:
        int cnt = 0;
    
        //storing elements in the temporary array in a sorted manner//
    
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1); //Modification 2
                right++;
            }
        }
    
        // if elements on the left half are still left //
    
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
    
        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
    
        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    
        return cnt; // Modification 3
    }
    
    int mergeSort(vector<int> &arr, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2 ;
        cnt += mergeSort(arr, low, mid);  // left half
        cnt += mergeSort(arr, mid + 1, high); // right half
        cnt += merge(arr, low, mid, high);  // merging sorted halves
        return cnt;
    }
    
    int numberOfInversions(vector<int>&a, int n) {
    
        // Count the number of pairs:
        return mergeSort(a, 0, n - 1);
    }
    
  public:

    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        // step 1: finding inorder traversal of given tree
        vector<int> arr;
        inOrder(root, arr);
        
        // step 2: finding number of inversions in 'arr'
        return numberOfInversions(arr, n);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends