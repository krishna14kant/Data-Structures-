class Node:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right

    def __str__(self):
        return str(self.data)


class BST:
    def __init__(self):
        self.root = None
        self.result_inOrder = ""

    def insert(self, data, root):
        if root is None:
            return Node(data)
        else:
            if root.data == data:
                return root
            elif root.data > data:
                root.left = self.insert(data, root.left)
            else:
                root.right = self.insert(data, root.right)
        return root

    def printTree(self, node, level=0):
        if node != None:
            self.printTree(node.right, level + 1)
            print('     ' * level, node)
            self.printTree(node.left, level + 1)

    def findMax(self, root):
        if root is None:
            return float('-inf')

        res = root.data
        lres = self.findMax(root.left)
        rres = self.findMax(root.right)

        if lres > res:
            res = lres
        if rres > res:
            res = rres
        return res

    def findMin(self, root):
        if root is None:
            return float('inf')

        res = root.data
        rres = self.findMin(root.right)
        lres = self.findMin(root.left)

        if rres < res:
            res = rres
        if lres < res:
            res = lres
        return res

    def count_k(self, root, k):
        if root is None:
            return 0

        if root.data <= k:
            return (1 + self.count_k(root.left, k) + self.count_k(root.right, k))

        elif root.data > k:
            return self.count_k(root.left, k)

    def preOrder(self, root):
        if root is None:
            return

        print(root.data, end="")
        self.preOrder(root.left)
        self.preOrder(root.right)

    def inOrder(self, root):
        if root is None:
            return

        if root.left or root.right:
            self.result_inOrder += '('
        self.inOrder(root.left)
        self.result_inOrder += str(root.data)
        self.inOrder(root.right)
        if root.left or root.right:
            self.result_inOrder += ')'
        return self.result_inOrder

    def postOrder(self, root):
        if root is None:
            return

        self.postOrder(root.left)
        self.postOrder(root.right)
        print(root.data, end=' ')

    def breadth(self, root):
        if root is None:
            return
        queue = []
        queue.append(root)
        while len(queue) > 0:
            current = queue.pop(0)
            print(current.data, end=' ')
            if current.left:
                queue.append(current.left)
            if current.right:
                queue.append(current.right)


T = BST()
inp = input('Enter Postfix : ')
stack = []
for i in inp:
    if i in '+-*/':
        op1, op2 = stack.pop(), stack.pop()
        stack.append(Node(i, op2, op1))
    else:
        stack.append(Node(i))
root = stack.pop()
print("Tree :")
T.printTree(root)
print("--------------------------------------------------\nInfix : ", end='')
print(T.inOrder(root))
print("Prefix : ", end='')
T.preOrder(root)