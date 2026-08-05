from typing import List

class Solution:
    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        neighbours = [[] for _ in range(n)]
        for u, v in invocations:
            neighbours[u].append(v)
        
        suspicious = [False] * n
        suspicious[k] = True
        stack = [k]
        
        while stack:
            curr = stack.pop()
            for neighbor in neighbours[curr]:
                if not suspicious[neighbor]:
                    suspicious[neighbor] = True
                    stack.append(neighbor)

        for u, v in invocations:
            if suspicious[v] and not suspicious[u]:
                return list(range(n))
        
        return [i for i in range(n) if not suspicious[i]]

            

        