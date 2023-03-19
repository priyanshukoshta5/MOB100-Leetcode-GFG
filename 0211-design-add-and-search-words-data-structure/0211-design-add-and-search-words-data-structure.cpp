struct Node{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch){
        return (links[ch-'a'] != nullptr);
    }
    void setlink(char ch, Node* node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setflag(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
private:
    Node *root;

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node *node = root;
        for(char ch: word)
        {
            if(!node->containsKey(ch))
                node->setlink(ch, new Node());
            node = node->get(ch);
        }
        node->setflag();
    }

    bool helper(string& word, int pos, Node* node)
    {
        if(pos == word.length())
            return node->isEnd();

        bool ans = false;
        if(word[pos] == '.')
        {
            for(char ch='a'; ch<='z'; ch++)
            {
                if(node->containsKey(ch))
                    ans = ans || helper(word, pos+1, node->get(ch));
            }
        }
        else
        {
            if(!node->containsKey(word[pos]))
                ans = false;
            else
                ans = helper(word, pos+1, node->get(word[pos]));
        }

        return ans;
    }
    
    bool search(string word) {
        Node *node = root;
        return helper(word, 0, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */