//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        int s_freq[26] = {0};
        int list_freq[26] = {0};
        for(char c: s)
            s_freq[c-'a']++;
        
        int chars = 0;
        for(int i: s_freq)
            if(i > 0)
                chars++;
            
        vector<Node*> ans;
        Node* i = head;
        Node* j = head;
        int matched = 0;
        while(j != nullptr)
        {
            int val = j->data-'a';
            if(s_freq[val] == 0)
            {
                // Resetting
                j = j->next;
                i = j;
                for(int pos=0; pos<26; pos++)
                    list_freq[pos] = 0;
                matched = 0;
                continue;
            }
            
            list_freq[val]++;
            while(i!=j && list_freq[val]>s_freq[val])
            {
                int temp = i->data-'a';
                if(list_freq[temp] >= s_freq[temp])
                    matched--;
                list_freq[temp]--;
                i = i->next;
            }
            if(list_freq[val] == s_freq[val])
                matched++;
            
            // cout<<i->data<<" "<<j->data<<" "<<matched<<endl;
            if(matched == chars)
            {
                ans.push_back(i);
                
                // Resetting
                i = j;
                j = j->next;
                i->next = nullptr;
                i = j;
                for(int pos=0; pos<26; pos++)
                    list_freq[pos] = 0;
                matched = 0;
            }
            else
                j = j->next;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends