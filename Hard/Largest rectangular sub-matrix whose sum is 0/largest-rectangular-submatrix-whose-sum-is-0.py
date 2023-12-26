from typing import List, Tuple
from collections import defaultdict


class Solution:
    def sum_zero(self, temp: List[int], starti: List[int], endj: List[int], n: int) -> bool:
        presum = defaultdict(int)
        sum_ = 0
        # Initialize length of sub-array with sum 0
        max_length = 0
        for i in range(n):
            sum_ += temp[i]
            if temp[i] == 0 and max_length == 0:
                starti[0] = i
                endj[0] = i
                max_length = 1
            if sum_ == 0:
                if max_length < i + 1:
                    starti[0] = 0
                    endj[0] = i
                max_length = i + 1
            if sum_ in presum:
                old = max_length
                max_length = max(max_length, i - presum[sum_])
                if old < max_length:
                    endj[0] = i
                    starti[0] = presum[sum_] + 1
            else:
                presum[sum_] = i
        return max_length != 0
    
    def sumZeroMatrix(self, a : List[List[int]]) -> List[List[int]]:
        row = len(a)
        col = len(a[0])
        
        temp = [0] * row
        # Variables to store the final output
        fup = fdown = fleft = fright = 0
        maxl = float('-inf')
        # Set the left column
        for left in range(col):
            temp = [0] * row
            # Set the right column for the left column
            # set by outer loop
            for right in range(left, col):
     
                # Calculate sum between current left
                # and right for every row 'i'
                for i in range(row):
                    temp[i] += a[i][right]
                up, down = [0], [0]
     
                # Find largest subarray with 0 sum in
                # temp[]. The sumZero() function also
                # sets values of start and finish. So
                # 'sum' is sum of rectangle between (start,
                # left) and (finish, right) which is
                # boundary columns strictly as left and right.
                s = self.sum_zero(temp, up, down, row)
                ele = (down[0] - up[0] + 1) * (right - left + 1)
     
                # Compare no. of elements with previous
                # no. of elements in sub-Matrix.
                # If new sub-matrix has more elements
                # then update maxl and final boundaries
                # like fup, fdown, fleft, fright
                if s and ele > maxl:
                    fup = up[0]
                    fdown = down[0]
                    fleft = left
                    fright = right
                    maxl = ele
     
        if fup == fdown == fleft == fright == 0 and a[0][0] != 0:
            return [[]]
            
        ans = []
        for j in range(fup, fdown+1):
            r = []
            for i in range(fleft, fright+1):
                r.append(a[j][i])
            ans.append(r)
            
        return ans;
        



#{ 
 # Driver Code Starts

class IntArray:
    def __init__(self) -> None:
        pass
    def Input(self,n):
        arr=[int(i) for i in input().strip().split()]#array input
        return arr
    def Print(self,arr):
        for i in arr:
            print(i,end=" ")
        print()



class IntMatrix:
    def __init__(self) -> None:
        pass
    def Input(self,n,m):
        matrix=[]
        #matrix input
        for _ in range(n):
            matrix.append([int(i) for i in input().strip().split()])
        return matrix
    def Print(self,arr):
        for i in arr:
            for j in i:
                print(j,end=" ")
            print()


if __name__=="__main__":
    t = int(input())
    for _ in range(t):
        
        nm=IntArray().Input(2)
        
        
        a=IntMatrix().Input(nm[0], nm[1])
        
        obj = Solution()
        res = obj.sumZeroMatrix(a)
        if len(res) == 0:
            print(-1)
        else:
            IntMatrix().Print(res)
        

# } Driver Code Ends