struct Node{
    Node *links[26];
    bool flag = false;  // to check that it is the end of word or not

    bool isValidLink(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

// integrated Trie functions within Solution class
class Solution {
private:
    Node *root = new Node();

    void insertWord(string &word){
        Node *temp = root;
        for(char ch: word)
        {
            if(!temp->isValidLink(ch))
                temp->links[ch - 'a'] = new Node();
            temp = temp->links[ch - 'a'];
        }
        temp->setEnd();
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();

        // Trie to store words
        for(string x: dictionary)
            insertWord(x);

        vector<int> dp(n + 1, 0);
        // base case
        dp[n] = 0;

        for(int i = n - 1; i >= 0; i--)
        {
            int res = n - i;
            Node *temp = root;

            for(int j = i; j < n; j++)
            {
                if(!temp->isValidLink(s[j]))    // no longer word exits
                {
                    res = min(res, (j - i + 1) + dp[j + 1]);
                    break;
                }

                temp = temp->links[s[j] - 'a'];
                if(temp->isEnd())               // word found in dictionary
                    res = min(res, dp[j + 1]);
                else                            // word not found in dictionary
                    res = min(res, (j - i + 1) + dp[j + 1]);
            }

            dp[i] = res;
        }

        return dp[0];
    }
};