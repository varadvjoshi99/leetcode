from typing import List 

class Solution:
    def minimumSemesters(self, n: int, relations: List[List[int]]) -> int:
        from functools import cache
        visited = [0] * (n + 1)
        adj_list = [[] for _ in range(n+1)]
        degree = set(list(_ for _ in range(1, n+1)))

        for pre, post in relations:
            adj_list[pre].append(post)
            degree.discard(post)

        def has_cycle(i):
            if visited[i] == 2:
                return False
            elif visited[i] == 1:
                return True
            else:
                visited[i] = 1
                for j in adj_list[i]:
                    if has_cycle(j):
                        return True
                    
                visited[i] = 2
                return False
        
        for i in range(n):
            if has_cycle(i):
                return -1

        @cache
        def dfs(course, semester=1):
            
            res = semester
            for j in adj_list[course]:
                res = max(res, 1 + dfs(j))

            return res

        result = 0
        for j in degree:
            result = max(result, dfs(j))
            
        return result