#User function Template for python3

class Solution:
    def reversedBits(self, x):
        a = bin(x)
        a = '0b' + '0'*(32 - len(a[2:])) + a[2:]
        # print(a)
        a = '0b' + a[2:][::-1]
        # print(a)
        return int(a, 2)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int (input ())
    for _ in range (t):
        X=int(input())
        
        ob = Solution()
        print(ob.reversedBits(X))
# } Driver Code Ends