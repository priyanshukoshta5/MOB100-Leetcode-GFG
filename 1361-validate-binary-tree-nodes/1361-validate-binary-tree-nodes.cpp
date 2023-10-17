class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(leftChild[i] != -1)
                inDegree[leftChild[i]]++;
            if(rightChild[i] != -1)
                inDegree[rightChild[i]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(inDegree[i] == 0)
                q.push(i);
            if(inDegree[i] > 1 || q.size() > 1)
                return false;
        }

        int total = n;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            total--;

            int left = leftChild[node];
            if(left != -1)
            {
                inDegree[left]--;
                if(inDegree[left] == 0)
                    q.push(left);
            }

            int right = rightChild[node];
            if(right != -1)
            {
                inDegree[right]--;
                if(inDegree[right] == 0)
                    q.push(right);
            }
        }

        return total == 0;
    }
};