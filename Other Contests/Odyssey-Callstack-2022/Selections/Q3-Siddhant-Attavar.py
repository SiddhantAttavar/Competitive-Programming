n, m, k = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
	u, v = map(int, input())
	graph[u].append(v)
	graph[u].append(v)
