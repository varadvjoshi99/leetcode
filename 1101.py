from typing import List

class Solution:
    def earliestAcq(self, logs: List[List[int]], n: int) -> int:
        logs.sort()
        group = [i for i in range(n)]
        components = n

        def find(i):
            while i != group[i]:
                i = group[i]
            return i

        for time, a, b in logs:
            group_a, group_b = find(a), find(b)
            if group_a != group_b:
                group[group_b] = group_a
                components -= 1
            
            if components == 1:  
                return time

        return -1

        