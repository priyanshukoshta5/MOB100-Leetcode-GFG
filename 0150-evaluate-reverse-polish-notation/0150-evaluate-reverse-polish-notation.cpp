class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string t: tokens)
        {
            if(t == "+")
            {
                int a = st.top();   st.pop();
                int b = st.top();   st.pop();
                st.push(b + a);
            }
            else if(t == "-")
            {
                int a = st.top();   st.pop();
                int b = st.top();   st.pop();
                st.push(b - a);
            }
            else if(t == "*")
            {
                int a = st.top();   st.pop();
                int b = st.top();   st.pop();
                st.push(b * a);
            }
            else if(t == "/")
            {
                int a = st.top();   st.pop();
                int b = st.top();   st.pop();
                st.push(b / a);
            }
            else
                st.push(stoi(t));
        }

        return st.top();
    }
};