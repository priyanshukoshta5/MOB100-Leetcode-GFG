//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

bool compare(pair<int, Node*> &a, pair<int, Node*> &b){
    return a.first < b.first;
}

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        vector<pair<int, Node *>> arr;
        for(Node *h = head; h != nullptr; h = h->next)
            arr.push_back({h->data, h});
        
        sort(arr.begin(), arr.end(), compare);
        
        head = arr[0].second;
        arr[0].second->prev = nullptr;
        for(int i = 1; i < arr.size(); i++)
        {
            arr[i - 1].second->next = arr[i].second;
            arr[i].second->prev = arr[i - 1].second;
        }
        arr[arr.size() - 1].second->next = nullptr;
        return head;
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends