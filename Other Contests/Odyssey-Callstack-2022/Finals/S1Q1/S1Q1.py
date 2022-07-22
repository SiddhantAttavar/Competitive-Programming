def dfs(u):
	visited[u] = True
	inStack[u] = True
	for v in graph[u]:
		if inStack[v]:
			return True
		if not visited[v] and dfs(v):
			return True
	inStack[u] = False
	return False

n, k = map(int, input().split())
graph = [[] for _ in range(n)]
root = set(range(n))
for _ in range(k):
	u, v = map(int, input().split())
	graph[v].append(u)
	if u in root:
		root.remove(u)

visited = [False] * n
inStack = [False] * n
if len(root) == 0:
	print(0)
else:
	for i in root:
		if dfs(i):
			print(0)
			break
	else:
		print(1)
