class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(auto i: students)
            q.push(i);

        int s = 0;

        bool consumed = true;
        while(s < sandwiches.size() && consumed)
        {
            int n = q.size();
            consumed = false;
            while(n--)
            {
                if(q.front() == sandwiches[s])
                {
                    q.pop();
                    s++;
                    consumed = true;
                }
                else
                {
                    q.push(q.front());
                    q.pop();
                }
            }
        }

        return (sandwiches.size() - s);
    }
};