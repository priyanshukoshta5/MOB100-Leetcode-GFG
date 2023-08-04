//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    int i = 0;
    
    void insertAtBottom(stack<int> &st, int cur){
        if(st.size() == i)
        {
            st.push(cur);
            return;
        }
        int val = st.top();
        st.pop();
        insertAtBottom(st, cur);
        st.push(val);
    }

public:
    void Reverse(stack<int> &st){
        if(i == st.size())
            return;
            
        int cur = st.top();
        st.pop();
        insertAtBottom(st, cur);
            
        i++;
        Reverse(st);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends