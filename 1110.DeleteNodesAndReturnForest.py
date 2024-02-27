from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        LEFT, RIGHT = 0, 1

        def forest(root, included = False, parent = None, parent_direction = None):

            if not root:
                return []

            if root.val in to_delete:
                if parent:
                    if parent_direction == LEFT:
                        parent.left = None
                    elif parent_direction == RIGHT:
                        parent.right = None

                left_child, right_child = root.left, root.right
                root.left, root.right = None, None    
                return forest(left_child, False) + forest(right_child, False)

            if included:
                return forest(root.left, included, root, LEFT) + forest(root.right, included, root, RIGHT)
            else:
                return [root] + forest(root.left, True, root, LEFT) + forest(root.right, True, root, RIGHT)

        return forest(root, False)
