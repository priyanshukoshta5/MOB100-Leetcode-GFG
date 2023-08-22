#User function Template for python3

class Solution:
    def findMinOpeartion(self, matrix, n):
        sumRow = [0] * n
        sumCol = [0] * n
        for i in range(n):
             for j in range(n):
                 sumRow[i] += matrix[i][j]
                 sumCol[j] += matrix[i][j]
                 
        maxSum=0
        for i in range(n):
            maxSum = max(maxSum, sumRow[i])
            maxSum = max(maxSum, sumCol[i])
        count=0
        i=0
        j=0
        while i < n and j < n:
            diff = min(maxSum - sumRow[i],maxSum - sumCol[j])
            matrix[i][j] += diff
            sumRow[i] += diff
            sumCol[j] += diff
            count += diff
            if (sumRow[i] == maxSum):
                i+=1
            if (sumCol[j] == maxSum):
                j+=1
                
        return count


#{ 
 # Driver Code Starts

#Initial Template for Python 3

for _ in range(int(input())):
    n = int(input())
    matrix = [list(map(int,input().split())) for _ in range(n)]
    ob = Solution()
    print(ob.findMinOpeartion(matrix, n))
# } Driver Code Ends