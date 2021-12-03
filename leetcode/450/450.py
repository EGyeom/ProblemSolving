# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if root == None:
            return None
        if key < root.val:
            root.left = self.deleteNode(root.left,key)
        elif key > root.val:
            root.right = self.deleteNode(root.right,key)
        else:
            if root.left == None:
                return root.right
            elif root.right == None:
                return root.left
            else:
                temp = self.find_min(root.right)
                root.val = temp.val
                root.right = self.deleteNode(root.right,root.val)
                return root
        return root
    
    def find_min(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root.left != None:
            return self.find_min(root.left)
        return root