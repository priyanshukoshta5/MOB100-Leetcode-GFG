//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        Node *prev1 = node1;
        Node *prev2 = node2;
        Node *next;
        Node *newHead = nullptr;
        while(prev1 != nullptr && prev2 != nullptr)
        {
            if(prev1->data < prev2->data)
            {
                next = prev1->next;
                prev1->next = newHead;
                newHead = prev1;
                prev1 = next;
            }
            else
            {
                next = prev2->next;
                prev2->next = newHead;
                newHead = prev2;
                prev2 = next;
            }
        }
        
        while(prev1 != nullptr)
        {
            next = prev1->next;
            prev1->next = newHead;
            newHead = prev1;
            prev1 = next;
        }
        
        while(prev2 != nullptr)
        {
            next = prev2->next;
            prev2->next = newHead;
            newHead = prev2;
            prev2 = next;
        }
        
        return newHead;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends