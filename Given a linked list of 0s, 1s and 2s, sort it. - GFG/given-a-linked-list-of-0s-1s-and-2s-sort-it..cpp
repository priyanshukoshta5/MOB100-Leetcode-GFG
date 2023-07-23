//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        Node *zero = new Node(-1);
        Node *curZero = zero;
        
        Node *one = new Node(-1);
        Node *curOne = one;
        
        Node *two = new Node(-1);
        Node *curTwo = two;
        
        Node *cur = head;
        while(cur != nullptr)
        {
            Node* temp = cur->next;
            
            if(cur->data == 0)
            {
                curZero->next = cur;
                curZero = curZero->next;
                curZero->next = nullptr;
            }
            else if(cur->data == 1)
            {
                curOne->next = cur;
                curOne = curOne->next;
                curOne->next = nullptr;
            }
            else if(cur->data == 2)
            {
                curTwo->next = cur;
                curTwo = curTwo->next;
                curTwo->next = nullptr;
            }
            
            cur = temp;
        }
        
        Node* newHead = new Node(-1);
        cur = newHead;
        
        if(zero->next != nullptr)
        {
            cur->next = zero->next;
            cur = curZero;
        }
        if(one->next != nullptr)
        {
            cur->next = one->next;
            cur = curOne;
        }
        if(two->next != nullptr)
        {
            cur->next = two->next;
            cur = curTwo;
        }
        cur->next = nullptr;
        
        return newHead->next;
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends