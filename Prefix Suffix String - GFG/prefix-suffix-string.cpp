//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

struct Node{
    Node *links[26];
    bool flag;
    
    bool containsKey(char ch){
        return (links[ch-'a'] != nullptr);
    }
    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(string& word){
            Node *node = root;
            for(int i=0; i<word.size(); i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }
        bool startsWith(string& word){
            Node *node = root;
            for(int i=0; i<word.size(); i++){
                if(!node->containsKey(word[i]))
                    return false;
                node = node->get(word[i]);
            }
            return true;
        }
};

class Solution{
private:
    Trie prefix;
    Trie suffix;
    
private:
    void constructPrefixTrie(vector<string>& words){
        for(string s: words)
            prefix.insert(s);
    }
    void constructSuffixTrie(vector<string>& words){
        for(string s: words)
        {
            string rev = s;
            reverse(rev.begin(), rev.end());
            suffix.insert(rev);
        }
    }
    
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        
        constructPrefixTrie(s1);
        constructSuffixTrie(s1);
        
        int cnt = 0;
        for(string s: s2)
        {
            if(prefix.startsWith(s) == true)
            {
                cnt++;
                continue;
            }
            
            string rev = s;
            reverse(rev.begin(), rev.end());
            if(suffix.startsWith(rev) == true)
                cnt++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends