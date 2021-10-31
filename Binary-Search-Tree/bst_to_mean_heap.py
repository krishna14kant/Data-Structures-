class Node:
 
    # Constructor to create a new node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
 
# function for the inorder traversal
# of the tree so as to store the node
# values in 'arr' in sorted order
def inorderTraversal(root, arr):
    if root == None:
        return
 
    # first recur on left subtree
    inorderTraversal(root.left, arr)
 
    # then copy the data of the node
    arr.append(root.data)
 
    # now recur for right subtree
    inorderTraversal(root.right, arr)
     
# function to convert the given
# BST to MIN HEAP performs preorder
# traversal of the tree
def BSTToMinHeap(root, arr, i):
    if root == None:
        return
 
    # first copy data at index 'i' of
    # 'arr' to the node
    i[0] += 1
    root.data = arr[i[0]]
 
    # then recur on left subtree
    BSTToMinHeap(root.left, arr, i)
 
    # now recur on right subtree
    BSTToMinHeap(root.right, arr, i)
 
# utility function to convert the
# given BST to MIN HEAP
def convertToMinHeapUtil(root):
     
    # vector to store the data of
    # all the nodes of the BST
    arr = []
    i = [-1]
 
    # inorder traversal to populate 'arr'
    inorderTraversal(root, arr);
 
    # BST to MIN HEAP conversion
    BSTToMinHeap(root, arr, i)
     
# function for the preorder traversal
# of the tree
def preorderTraversal(root):
    if root == None:
        return
 
    # first print the root's data
    print(root.data, end = " ")
 
    # then recur on left subtree
    preorderTraversal(root.left)
 
    # now recur on right subtree
    preorderTraversal(root.right)
     
# Driver Code
if __name__ == '__main__':
     
    # BST formation
    root = Node(4)
    root.left = Node(2)
    root.right = Node(6)
    root.left.left = Node(1)
    root.left.right = Node(3)
    root.right.left = Node(5)
    root.right.right = Node(7)
 
    convertToMinHeapUtil(root)
    print("Preorder Traversal:")
    preorderTraversal(root)
