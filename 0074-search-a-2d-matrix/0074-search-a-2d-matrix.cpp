class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low=0, mid, high=n-1;
        int row = -1;
        // Searching for column target may be found
        while(low <= high)
        {
            mid = low+(high-low)/2;
            if(target < matrix[mid][0])
                high = mid-1;
            else
            {
                row = mid;
                low = mid+1;
            }
        }
        
        if(row == -1)
            return false;
        
        // Search row for the target value
        low = 0;
        high = m-1;
        while(low <= high)
        {
            mid = low+(high-low)/2;
            if(target == matrix[row][mid])
                return true;
            else if(target < matrix[row][mid])
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
        
        // Time Complexity = O(log(n)+log(m)) = O(log(n*m))
    }
};