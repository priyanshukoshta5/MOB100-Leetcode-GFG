class Node{
    private:
        Node *links[26];
        bool flag = false;
    public:
        bool containsKey(char ch)
        {
            return (links[ch-'a'] != nullptr);
        }
        Node *getNode(char ch)
        {
            return links[ch-'a'];
        }
        void setLink(char ch, Node* node)
        {
            links[ch-'a'] = node;
        }
        void setEnd()
        {
            flag = true;
        }
        bool isEnd()
        {
            return flag;
        }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(char ch: word)
        {
            if(!node->containsKey(ch))
                node->setLink(ch, new Node());
            node = node->getNode(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(char ch: word)
        {
            if(!node->containsKey(ch))
                return false;
            node = node->getNode(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(char ch: prefix)
        {
            if(!node->containsKey(ch))
                return false;
            node = node->getNode(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */