class TreeNode:
  def __init__(self, x):
    self.val=x
    self.left=None
    self.right=None

myTree= TreeNode(5)
myTree.left= TreeNode(3)
myTree.right= TreeNode(8) 
myTree.left.left= TreeNode(1)
myTree.left.right=TreeNode(4)
myTree.right.right=TreeNode(12)

def getHeight(root):
  #base case
  if root is None: return 0
  # recursion rule
  return max(getHeight(root.left),getHeight(root.right))+1

print(getHeight(myTree))