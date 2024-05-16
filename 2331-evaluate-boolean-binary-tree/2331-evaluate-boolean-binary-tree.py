# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        def solve(root):
            if root.val in [0, 1]:
                return root.val
            if root.val == 2:
                if solve(root.left):
                    return True
                return solve(root.right)
            if root.val == 3:
                if solve(root.left) == False:
                    return False
                return solve(root.right)
        return solve(root)