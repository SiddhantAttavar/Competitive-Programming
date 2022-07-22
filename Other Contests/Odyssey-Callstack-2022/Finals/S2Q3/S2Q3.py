from sys import setrecursionlimit
setrecursionlimit(int(1e6))

def dfs(u, graph, color):
	for v, w in graph[u]:
		if color[v] == -1:
			if w:
				color[v] = 1 - color[u]
			else:
				color[v] = color[u]
			if not dfs(v, graph, color):
				return False
		else:
			if w and color[v] == color[u]:
				return False
			elif not w and color[v] != color[u]:
				return False
	return True

def check(m):
	color = [-1] * n
	graph = [[] for _ in range(n)]
	for i in range(n):
		graph[i].append((i, 0))
	for u, v, w in edges[:m]:
		u -= 1
		v -= 1
		graph[v].append((u, w))
		graph[u].append((v, w))
	for i in range(n):
		if color[i] == -1:
			color[i] = 0
			if not dfs(i, graph, color):
				return False
	return True

n, p = map(int, input().split())
edges = []
for _ in range(p):
	edges.append(list(map(int, input().split())))

l = 0
r = p
res = 0
while l <= r:
	m = (l + r) // 2
	if check(m):
		res = m
		l = m + 1
	else:
		r = m - 1
print(res)
