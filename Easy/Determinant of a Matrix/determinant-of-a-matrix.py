
#User function Template for python3

# ~aditya

class Solution:
    def determinantOfMatrix(self,matrix,n):
        if n==1:
            return matrix[0][0]
        if n==2:
            return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]
        ans = 0
        for i in range(n):
            mat=[matrix[j][1:] for j in range(n) if j!=i]
            ans+=((-1)**(i))*matrix[i][0]*self.determinantOfMatrix(mat,n-1)
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        values = list(map(int, input().strip().split()))
        k = 0
        matrix =[]
        for i in range(n):
            row=[]
            for j in range(n):
                row.append(values[k])
                k+=1
            matrix.append(row)
        obj = Solution()
        print(obj.determinantOfMatrix(matrix,n))
# } Driver Code Ends