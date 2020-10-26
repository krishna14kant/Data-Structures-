# https://leetcode.com/problems/inorder-successor-in-bst/
class Solution:
    def __init__(self):
        self.res = []

    def inorder(self, root):
        if root:
            self.inorder(root.left)
            self.res.append(int(root.val))
            self.inorder(root.right)

    def inorderSuccessor(self, root: 'TreeNode', p: 'TreeNode') -> 'TreeNode':
        self.inorder(root)
        value = p.val
        if value in self.res:
            ind = self.res.index(value)
            if ind + 1 >= len(self.res):
                return None
            else:
                return TreeNode(self.res[ind + 1])
        else:
            return None