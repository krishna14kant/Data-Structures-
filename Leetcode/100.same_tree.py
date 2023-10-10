# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isSameTree(self, p, q):
        # Base case: if both nodes are None, they are the same
        if p is None and q is None:
            return True
        
        # If one of the nodes is None, they are different
        if p is None or q is None:
            return False
        
        # If the values of the nodes are not equal, they are different
        if p.val != q.val:
            return False
        
        # Recur for left and right subtrees
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)

# Example usage
opt = Solution()
root = TreeNode(1, TreeNode(2), TreeNode(3))
root1 = TreeNode(1, TreeNode(2), TreeNode(3))
print(opt.isSameTree(root, root1))
