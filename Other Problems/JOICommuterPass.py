from collections import defaultdict

#Input
n, m = map(int, input().split())
s, t = map(int, input().split())
u, v = map(int, input().split())

graph = defaultdict(lambda: [])
for i in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))

minDistance = [-1] * n
def minDFS(u, t):
    if u == t:
        return 0
    
    if minDistance[u] != -1:
        return minDistance[u]
    
    res = 10 ** 10
    