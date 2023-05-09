class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> spiral;

        int i=0, j=0;
        int dir = 0;    // 0->top row, 1->last col, 2->bottom-row, 3->first col
        int leftBoundary = -1, rightBoundary = m-1, topBoundary = -1, bottomBoundary = n-1;
        while(topBoundary < bottomBoundary && leftBoundary < rightBoundary)
        {
            if(dir == 0)    // Moving Left to Right
            {
                while(j < rightBoundary)
                    spiral.push_back(matrix[i][j++]);
                topBoundary++;
            }
            else if(dir == 1)   // Moving Top to Bottom
            {
                while(i < bottomBoundary)
                    spiral.push_back(matrix[i++][j]);
                rightBoundary--;
            }  
            else if(dir == 2)   // Moving Right to Left
            {
                while(j > leftBoundary+1)
                    spiral.push_back(matrix[i][j--]);
                bottomBoundary--;
            }
            else if(dir == 3)    // Moving Bottom to Top
            {
                while(i > topBoundary+1)
                    spiral.push_back(matrix[i--][j]);
                leftBoundary++;
            }
            dir = (dir+1) % 4;
        }
        if(spiral.size() < (n*m))
            spiral.push_back(matrix[i][j]);

        return spiral;
    }
};