from typing import List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def averageOfSubtree(self, root: TreeNode) -> int:
        from functools import cache

        @cache
        def sum_and_count(node):
            if not node:
                return 0, 0
            if not node.left and not node.right:
                return node.val, 1
                
            total, count = node.val, 1
            left_total, left_count = sum_and_count(node.left)
            right_total, right_count = sum_and_count(node.right)

            return total + left_total + right_total, count + left_count + right_count

        q = [root]
        result = 0

        while q:
            next = []

            for node in q:
                total, count = sum_and_count(node)
                if total // count == node.val:
                    result += 1

                if node.left: next.append(node.left)
                if node.right: next.append(node.right)

            q = next

        return result