class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26] = {0};
        for(char ch: s)
            freq[ch - 'a']++;

        stack<char> st;
        bool visited[26] = {false};
        for(char ch: s)
        {
            while(!st.empty() && visited[ch - 'a'] == false && st.top() >= ch && freq[st.top() - 'a'] > 0)
            {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            freq[ch - 'a']--;
            if(visited[ch - 'a'] == false)
            {
                st.push(ch);
                visited[ch - 'a'] = true;
            }
        }

        string unique;
        while(!st.empty())
        {
            unique.push_back(st.top());
            st.pop();
        }

        reverse(unique.begin(), unique.end());

        return unique;
    }
};