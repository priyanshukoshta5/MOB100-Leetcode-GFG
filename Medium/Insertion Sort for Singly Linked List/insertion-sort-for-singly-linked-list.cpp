//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        Node *newHead = new Node(-1);
        newHead->next = head_ref;
        Node *prev = newHead;
        Node *curr = prev->next;
        
        while(curr != nullptr)
        {
            if(curr->data >= prev->data)
            {
                prev = curr;
                curr = curr->next;
                continue;
            }
            
            Node *next = curr->next;
            
            Node *tempPrev = newHead;
            Node *tempCurr = newHead->next;
            while(tempCurr != nullptr && curr->data > tempCurr->data)
            {
                tempPrev = tempCurr;
                tempCurr = tempCurr->next;
            }
            tempPrev->next = curr;
            curr->next = tempCurr;
            
            prev->next = next;
            curr = next;
        }
        
        return newHead->next;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends