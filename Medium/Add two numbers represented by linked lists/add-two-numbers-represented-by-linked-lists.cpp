//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    private:
    Node* reverseLL(Node* ll){
        if(ll == nullptr || ll->next == nullptr)
            return ll;
        
        Node *cur = ll, *prev = nullptr;
        while(cur)
        {
            Node *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
    
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        Node *newHead = new Node(0);
        Node *cur = newHead;
        Node *l1 = reverseLL(num1);
        Node *l2 = reverseLL(num2);
        int rem = 0;
        while(l1 || l2)
        {
            int val = rem;
            if(l1)
            {
                val += l1->data;
                l1 = l1->next;
            }
            if(l2)
            {
                val += l2->data;
                l2 = l2->next;
            }
            cur->next = new Node(val % 10);
            rem = val / 10;
            cur = cur->next;
        }
        if(rem != 0)
            cur->next = new Node(rem);
        newHead = reverseLL(newHead->next);
        while(newHead->next != nullptr && newHead->data == 0)
            newHead = newHead->next;
        return newHead;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends