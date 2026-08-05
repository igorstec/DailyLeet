from typing import List

class Solution:
    def dfs(self, node, neighbours, suspicious, susNodes):
        suspicious[node] = True
        susNodes.append(node)
        for neigh in neighbours[node]:
            if not suspicious[neigh]:
                self.dfs(neigh, neighbours, suspicious, susNodes)

    def remainingMethods(self, n: int, k: int, invocations: List[List[int]]) -> List[int]:
        lookingAtMe = [[] for _ in range(n)]
        neighbours = [[] for _ in range(n)]
        suspicious = [False] * n
        susNodes = []

        for edge in invocations:
            neighbours[edge[0]].append(edge[1])
            lookingAtMe[edge[1]].append(edge[0])
        
        self.dfs(k, neighbours, suspicious, susNodes)

        for node in susNodes:
            for looker in lookingAtMe[node]:
                if not suspicious[looker]:
                    return [i for i in range(n)]
        
        return [i for i in range(n) if not suspicious[i]]

            

        