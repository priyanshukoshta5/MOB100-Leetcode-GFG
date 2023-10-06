//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    private:
    Node *reverseLL(struct Node* ll){
        if(ll == nullptr || ll -> next == nullptr)
            return ll;
            
        struct Node* prev = nullptr;
        struct Node* cur = ll;
        
        while(cur != nullptr)
        {
            struct Node* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        return prev;
    }
    
    public:
    void rearrange(struct Node *odd)
    {
        if(odd == nullptr || odd -> next == nullptr)
            return;
        
        struct Node *list1 = odd;
        struct Node *l1 = list1;
        
        struct Node *list2 = odd->next;
        struct Node *l2 = list2;
        
        // extracting list 1 and list 2 from the given linked list
        while(l2 != nullptr && l2->next != nullptr)
        {
            l1->next = l2->next;
            l2->next = l2->next->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        l1->next = nullptr;
        
        // printing list1 and list2
        // for(auto i = list1; i != nullptr; i = i->next)  cout<<i->data<<" ";
        // cout<<endl;
        // for(auto i = list2; i != nullptr; i = i->next)  cout<<i->data<<" ";
        // cout<<endl<<endl;;
        
        // reversing list2;
        list2 = reverseLL(list2);
        
        // appending extracted list2 at the end of list1
        l1->next = list2;
        
        // no need to assign odd = list1 because list1 is pointer of odd
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends