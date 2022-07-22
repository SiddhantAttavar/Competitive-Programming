def dfs(u):
	dp[u] = a[u]
	for v in graph[u]:
		dfs(v)
		if len(graph[v]) == 0:
			dp[u] += 0
		elif len(graph[v]) == 1:
			dp[u] += dp[graph[v][0]]
		else:
			dp[u] += max(dp[graph[v][0]], dp[graph[v][1]])
	t = 0
	for v in graph[u]:
		t += dp[v]
	dp[u] = max(dp[u], t, 0)

def dfs1(u):
	for v in graph[u]:
		if a[v] == -1:
			for k in graph[v]:
				graph[u][]
				

a = list(map(int, input().split()))
n = len(a)

graph = [[] for _ in range(n)]
for i in range(n):
	if i * 2 + 1 < n:
		graph[i].append(i * 2 + 1)
	if i * 2 + 2 < n:
		graph[i].append(i * 2 + 2)

dp = [0] * n
dfs1(0)
dfs(0)
# print(*dp)
print(max(dp))
