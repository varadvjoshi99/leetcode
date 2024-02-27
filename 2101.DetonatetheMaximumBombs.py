from typing import List

class Solution:
    def maximumDetonation(self, bombs: List[List[int]]) -> int:
        
        def distance(x1, y1, x2, y2):
            import math
            return math.sqrt((x1-x2) ** 2 + (y1 - y2) ** 2)

        n = len(bombs)
        adj_list = [[] for _ in range(n)]

        # creating adjacency list
        for i in range(n-1):
            for j in range(i + 1, n):
                bomb_distance = distance(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1])
                radius1, radius2 = bombs[i][2], bombs[j][2]

                if bomb_distance <= radius1:
                    adj_list[i].append(j)
                if bomb_distance <= radius2:
                    adj_list[j].append(i)

        def detonate(bomb):
            
            visited = [0] * n
            detonated = 0
            visited[bomb] = 1
            q = [bomb]

            while q:
                next_ = []

                for b in q:
                    detonated += 1
                    for neighbour in adj_list[b]:
                        if not visited[neighbour]:
                            visited[neighbour] = 1
                            next_.append(neighbour)
                        
                q = next_[:]

            return detonated

        result = 0
        for b in range(len(bombs)):
            result = max(result, detonate(b))

        return result