from typing import List 

class Solution:
    def minGroups(self, intervals: List[List[int]]) -> int:
        left, right = float('inf'), -float('inf')
        additions = []

        for a, b in intervals:
            left = min(left, a)
            right = max(right, b)
            additions.append((a, 1))
            additions.append((b + 1, -1))

        additions.sort()
        min_group = 0
        curr = 0
        for i in range(len(additions)):
            curr += additions[i][1]
            min_group = max(min_group, curr)

        return min_group