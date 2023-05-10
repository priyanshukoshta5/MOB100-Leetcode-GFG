class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int> (n));

        int val = 1;
        int i = 0, j = 0;
        int dir = 0;    // 0->top row, 1->last col, 2->bottom-row, 3->first col
        int leftBoundary = -1, rightBoundary = n-1, topBoundary = -1, bottomBoundary = n-1;
        while(topBoundary < bottomBoundary && leftBoundary < rightBoundary)
        {
            if(dir == 0)    // Moving Left to Right
            {
                while(j < rightBoundary)
                    mat[i][j++] = (val++);
                topBoundary++;
            }
            else if(dir == 1)   // Moving Top to Bottom
            {
                while(i < bottomBoundary)
                    mat[i++][j] = (val++);
                rightBoundary--;
            }  
            else if(dir == 2)   // Moving Right to Left
            {
                while(j > leftBoundary+1)
                    mat[i][j--] = (val++);
                bottomBoundary--;
            }
            else if(dir == 3)    // Moving Bottom to Top
            {
                while(i > topBoundary+1)
                    mat[i--][j] = (val++);
                leftBoundary++;
            }
            dir = (dir+1) % 4;
        }
        if(val == (n*n))
            mat[i][j] = (val++);

        return mat;
    }
};