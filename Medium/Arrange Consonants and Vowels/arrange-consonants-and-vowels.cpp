//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head) {
    if (head == NULL)
        return;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void append(struct Node **headRef, char data) {
    struct Node *new_node = new Node(data);
    struct Node *last = *headRef;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node *head)
    {
       //Code here
       
       Node* cons = head;
       Node* vowel = head;
       
       // Finding out the first vowel
       
    //   while(vowel != nullptr && !isVowel(vowel->data)){
    //       vowel = vowel->next;
    //   }
       
       // Mil gaya vowel 
       
       Node* vowHead = new Node(0);
       Node* prev = vowHead;
       
       // Now looping till I find vowels
       
       while(vowel != nullptr){
           if(isVowel(vowel->data)){
               Node* newVowel = new Node(vowel->data);
            //   cout<<vowel->data<<" ";
              prev->next = newVowel;
              prev = prev->next;
           }
           
           vowel = vowel->next;
       }
        
       
       // Finding the first consonant
    //   while(cons != nullptr && isVowel(cons->data)){
    //       cons = cons->next;
    //   }
       
       // Mil gaya first consonant 
       Node *consHead = new Node(0);
       Node *prevC = consHead;
       
        while(cons != nullptr){
           if(!isVowel(cons->data)){
               Node* newCons = new Node(cons->data);
            //   cout<<cons->data<<" ";
              prevC->next = newCons;
              prevC = prevC->next;
           }
           
           cons = cons->next;
       }
       
       //Deleting the original Linked List
       
    //   delete head;
       
       
       // Linking the two LLs together
       
      prev->next = consHead->next;
       
       return vowHead->next;
       
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        char tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
    return 0;
}

// } Driver Code Ends